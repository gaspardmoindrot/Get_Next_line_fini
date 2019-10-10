/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:30:05 by gmoindro          #+#    #+#             */
/*   Updated: 2019/05/17 15:32:49 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*str_dest;
	const unsigned char	*str_src;

	str_dest = (unsigned char*)dest;
	str_src = (const unsigned char*)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (str_src < str_dest)
		while (n--)
			str_dest[n] = str_src[n];
	else
		while (n--)
			*(str_dest++) = *(str_src++);
	return (dest);
}
