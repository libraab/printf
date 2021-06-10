/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:27:39 by abouhlel          #+#    #+#             */
/*   Updated: 2021/05/31 11:27:41 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	ch;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	ch = (unsigned char)c;
	while (n > 0)
	{
		*d = *s;
		d++;
		n--;
		if (*s == ch)
			return (d);
		s++;
	}
	return (NULL);
}
