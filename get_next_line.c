/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 11:37:33 by gmoindro          #+#    #+#             */
/*   Updated: 2019/06/17 15:41:02 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static unsigned int	ft_jump_line(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	return (len);
}

static char			*ft_tab(char *str1, char *str2, size_t len)
{
	char		*str;
	int			nb;
	char		*s;

	nb = ft_strlen(str1) + ++len;
	str = ft_strnew(nb);
	s = str;
	while (*str1)
		*str++ = *str1++;
	while (*str2 && --len > 0)
		*str++ = *str2++;
	*str = '\0';
	return (s);
}

static char			*ft_chang(char *tab)
{
	if (ft_strchr(tab, '\n'))
	{
		ft_strcpy(tab, ft_strchr(tab, '\n') + 1);
		return (tab);
	}
	if (ft_jump_line(tab) > 0)
	{
		ft_strcpy(tab, ft_strchr(tab, '\0'));
		return (tab);
	}
	return (NULL);
}

int					get_next_line(int const fd, char **line)
{
	int				r;
	char			buff[BUFF_SIZE + 1];
	static char		*tab[4864];
	char			*str;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (tab[fd] == NULL)
		tab[fd] = ft_strnew(0);
	while (!(ft_strchr(tab[fd], '\n'))
			&& (r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		str = tab[fd];
		tab[fd] = ft_tab(str, buff, r);
		free(str);
	}
	line[0] = ft_strsub(tab[fd], 0, ft_jump_line(tab[fd]));
	if (ft_chang(tab[fd]) == NULL)
		return (0);
	return (1);
}
