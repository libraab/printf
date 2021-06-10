/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:18:37 by abouhlel          #+#    #+#             */
/*   Updated: 2021/06/10 12:21:50 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_start_info(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = -1;
	info->type = 0;
	info->nbr_base = 10;
	info->nbr_sign = 1;
}

int	ft_check_zero(t_info *info)
{
	if ((info->minus == 1 || info->prec > -1) && info->type != '%')
		info->zero = 0;
	return (info->zero);
}

int	ft_print_format(va_list ap, char *format)
{
	int				i;
	int				lenght;
	t_info			*info;

	i = 0;
	lenght = 0;
	info = malloc(sizeof(t_info) * 1);
	if (!info)
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			lenght += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			ft_start_info(info);
			while (format[++i] != '\0' && !(ft_strchr(TYPE, format[i])))
				ft_check_flags(ap, format, info, i);
			info->type = format[i++];
			info->zero = ft_check_zero(info);
			lenght += ft_print_type(ap, info);
		}
	}
	free(info);
	return (lenght);
}

int	ft_printf(const char *format, ...)
{
	int				lenght;
	va_list			ap;

	va_start(ap, format);
	lenght = ft_print_format(ap, (char *)format);
	va_end(ap);
	return (lenght);
}
