/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:33:43 by abouhlel          #+#    #+#             */
/*   Updated: 2021/05/31 11:33:44 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;
	size_t		memlen;

	if (s == NULL)
		return (NULL);
	i = 0;
	memlen = ft_strlen(&s[start]);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (memlen < len)
		len = memlen;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (s[start + i] && i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
