/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:28:18 by abouhlel          #+#    #+#             */
/*   Updated: 2021/05/31 11:28:20 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*A;
	unsigned char	*B;

	A = (unsigned char *)s1;
	B = (unsigned char *)s2;
	while (n)
	{
		if (*A != *B)
			return (*A - *B);
		A++;
		B++;
		n--;
	}
	return (0);
}
