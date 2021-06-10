/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:19:31 by abouhlel          #+#    #+#             */
/*   Updated: 2021/06/10 17:41:49 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_baseset(char type)
{
	if (type == 'u' || type == 'd' || type == 'i')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

int	ft_nbrlen(unsigned long long nbr, t_info *info)
{
	int	i;

	i = 0;
	if (nbr == 0 && info->prec != 0)
		return (1);
	while (nbr)
	{
		i++;
		nbr /= info->nbr_base;
	}
	return (i);
}

int	ft_prec_nbr(unsigned long long nbr, t_info *info, char **buf)
{
	int		nbr_len;
	int		all_len;
	int		i;

	i = 0;
	nbr_len = ft_nbrlen(nbr, info);
	if (info->prec > nbr_len)
		all_len = info->prec;
	else
		all_len = nbr_len;
	*buf = (char *)malloc(sizeof(char) * all_len + 1);
	(*buf)[all_len] = '\0';
	while (nbr_len < all_len - i)
		(*buf)[i++] = '0';
	if (nbr == 0 && info->prec != 0)
		(*buf)[all_len - 1] = '0';
	i = 1;
	while (nbr)
	{
		(*buf)[all_len - i] = ft_baseset(info->type)[nbr % info->nbr_base];
		nbr /= info->nbr_base;
		i++;
	}
	return (all_len);
}

int	ft_print_nbr(unsigned long long nbr, t_info *info)
{
	char	*buf;
	int		buf_len;
	int		total_len;

	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->nbr_base = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)nbr < 0)
	{
		info->nbr_sign = -1;
		nbr *= -1;
	}
	buf_len = ft_prec_nbr(nbr, info, &buf);
	if (info->nbr_sign == -1 && info->zero == 0)
		buf_len += ft_put_sign(&buf);
	if (info->type == 'p')
		buf_len = ft_put_pointer_prefix(&buf);
	total_len = ft_put_width_str(&buf, info);
	if (info->nbr_sign == -1 && info->zero == 1 && buf_len >= info->width)
		total_len += ft_put_sign(&buf);
	if (info->nbr_sign == -1 && info->zero == 1 && buf_len < info->width)
		buf[0] = '-';
	ft_putstr(buf);
	free(buf);
	return (total_len);
}