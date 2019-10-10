/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:06:28 by gmoindro          #+#    #+#             */
/*   Updated: 2019/04/26 14:51:32 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_of_words(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (j == 0 && *s != c)
		{
			j = 1;
			i++;
		}
		else if (j == 1 && *s == c)
			j = 0;
		s++;
	}
	return (i);
}

static int		ft_strlen_mot(char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		nbr;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	nbr = ft_nb_of_words((char *)s, c);
	i = 0;
	if (!(tab = (char **)malloc((nbr + 1) * sizeof(char*))))
		return (NULL);
	while (nbr--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub((char *)s, 0, ft_strlen_mot((char *)s, c));
		if (!tab[i])
			return (NULL);
		s = s + ft_strlen_mot((char *)s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
