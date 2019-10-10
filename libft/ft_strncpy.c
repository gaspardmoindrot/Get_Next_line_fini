/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:53:10 by gmoindro          #+#    #+#             */
/*   Updated: 2019/04/25 14:37:52 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*str_dest;

	str_dest = dest;
	while (*src && n > 0)
	{
		*str_dest++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*str_dest++ = '\0';
		n--;
	}
	return (dest);
}
