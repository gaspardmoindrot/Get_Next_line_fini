/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:07:55 by gmoindro          #+#    #+#             */
/*   Updated: 2019/04/25 14:43:18 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	int				a;

	a = 0;
	str = (unsigned char*)s;
	while (n > 0)
	{
		str[a] = (unsigned char)c;
		n--;
		a++;
	}
	return (s);
}
