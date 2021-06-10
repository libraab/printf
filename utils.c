/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:20:28 by abouhlel          #+#    #+#             */
/*   Updated: 2021/06/10 17:38:55 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_pointer_prefix(char **buf)
{
	char	*newstr;
	int		x;

	x = 2;//ft_strlen("0x")
	newstr = (char *)malloc(sizeof(char) * (x + ft_strlen(*buf) + 1));
	if (!newstr)
		return (0);
	ft_strlcpy(newstr, ("0x"), x + 1);
	ft_strlcat(newstr + x, *buf, ft_strlen(*buf) + 1);
	free(*buf);
	*buf = newstr;
	return (ft_strlen(*buf));
}

int	ft_put_sign(char **buf)
{
	int		add_len;
	char	*newstr;
	int		y;

	y = 1;//ft_strlen("-")
	add_len = 0;
	newstr = (char *)malloc(sizeof(char) * (y + ft_strlen(*buf) + 1));
	if (!newstr)
		return (0);
	ft_strlcpy(newstr, ("-"), y + 1);
	ft_strlcat(newstr + y, *buf, ft_strlen(*buf) + 1);
	free(*buf);
	*buf = newstr;
	add_len = 1;
	return (add_len);
}