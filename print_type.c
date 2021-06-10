/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:20:11 by abouhlel          #+#    #+#             */
/*   Updated: 2021/06/07 18:33:31 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_type(va_list ap, t_info *info)
{
	int		length;
	char	type;

	length = 0;
	type = info->type;
	if (type == '%')
		length = ft_print_char('%', info);
	else if (type == 'c')
		length = ft_print_char(va_arg(ap, int), info);
	else if (type == 's')
		length = ft_print_string(va_arg(ap, char *), info);
	else if (type == 'p')
		length = ft_print_nbr(va_arg(ap, unsigned long long), info);
	else if (type == 'd' || type == 'i')
		length = ft_print_nbr(va_arg(ap, int), info);
	else if (type == 'x' || type == 'X' || type == 'u')
		length = ft_print_nbr(va_arg(ap, unsigned int), info);
	return (length);
}
