/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:53:25 by gmoindro          #+#    #+#             */
/*   Updated: 2019/04/25 17:06:20 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int		t;
	int					end;

	if (!s)
		return (NULL);
	t = 0;
	end = ft_strlen(s) - 1;
	while ((s[t] == ' ' || s[t] == '\t' || s[t] == '\n') && s[t])
		t++;
	while ((s[end] == ' ' || s[end] == '\t' || s[end] == '\n') && s[end] &&
			end > (int)t)
		end--;
	return (ft_strsub(s, t, (end - t + 1)));
}
