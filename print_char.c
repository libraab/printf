/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:19:15 by abouhlel          #+#    #+#             */
/*   Updated: 2021/06/10 12:26:29 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_char(int c, t_info *info)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	if (info->minus == 1)
		x = ft_putchar(c);
	while (y < info->width)
	{
		if (info->prec > -1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		y++;
		x++;
	}
	if (info->minus == 0)
		x += ft_putchar(c);
	return (x);
}
