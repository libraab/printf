/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:19:49 by abouhlel          #+#    #+#             */
/*   Updated: 2021/06/10 12:26:22 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_put_width_str(char **coco, t_info *info)
{
	int		i;
	char	*spaces;

	i = 0;
	if (info->width <= (int)ft_strlen(*coco))
		return ((int)ft_strlen(*coco));
	spaces = malloc(sizeof(char) * (info->width - ft_strlen(*coco) + 1));
	if (!spaces)
		return (0);
	while ((size_t)i < info->width - ft_strlen(*coco))
	{
		if (info->zero == 1)
			spaces[i] = '0';
		else
			spaces[i] = ' ';
		i++;
	}
	spaces[i] = '\0';
	if (info->minus == 0)
		*coco = ft_strjoin(spaces, *coco);
	else
		*coco = ft_strjoin(*coco, spaces);
	return (info->width);
}

int	ft_print_string(char *str, t_info *info)
{
	int		i;
	int		lenght;
	char	*coco;

	i = 0;
	lenght = 0;
	if (str == NULL)
		str = "(null)";
	if (info->prec == -1 || (size_t)info->prec > ft_strlen(str))
		info->prec = ft_strlen(str);
	coco = (char *)malloc(sizeof(char) * info->prec + 1);
	if (!coco)
		return (0);
	while (i < info->prec)
	{
		coco[i] = str[i];
		i++;
	}
	coco[i] = '\0';
	lenght = ft_put_width_str(&coco, info);
	ft_putstr(coco);
	free(coco);
	return (lenght);
}
