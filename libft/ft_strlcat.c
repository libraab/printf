/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:31:34 by abouhlel          #+#    #+#             */
/*   Updated: 2021/05/31 11:31:35 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;
	size_t	len_src;

	len = 0;
	len_src = ft_strlen((char *)src);
	while (dst[len] && len < dstsize)
		len = len + 1;
	i = len;
	while (src[len - i] && len + 1 < dstsize)
	{
		dst[len] = src[len - i];
		len = len + 1;
	}
	if (i < dstsize)
		dst[len] = '\0';
	return (len_src + i);
}
