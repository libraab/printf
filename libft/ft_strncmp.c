/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:32:32 by abouhlel          #+#    #+#             */
/*   Updated: 2021/05/31 11:32:33 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*S1;
	unsigned char	*S2;

	S1 = (unsigned char *)s1;
	S2 = (unsigned char *)s2;
	while ((*S1 || *S2) && n)
	{
		if (*S1 != *S2)
			return (*S1 - *S2);
		S1++;
		S2++;
		n--;
	}
	return (0);
}
