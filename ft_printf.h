/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:18:55 by abouhlel          #+#    #+#             */
/*   Updated: 2021/06/10 17:44:08 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h>

# define TYPE "csdiupxX%"

typedef struct s_info
{
	int			minus;
	int			zero;
	int			width;
	int			prec;
	char		type;
	int			nbr_base;
	int			nbr_sign;
}				t_info;

int				ft_printf(const char *format, ...);//shortcut
int				ft_print_format(va_list ap, char *format);//main function
int				ft_check_zero(t_info *info);//flag zero
void			ft_check_flags(va_list ap, char *format, t_info *info, int i);//manage all flag except zero
void			ft_width_prec(va_list ap, char *format, t_info *info, int i);//put width prec for flag digit or *
void			ft_start_info(t_info *info);//initializing my infos 
int				ft_print_type(va_list ap, t_info *info);//for converters
int				ft_print_char(int c, t_info *info);
int				ft_put_width(int width, int prec);
int				ft_print_string(char *str, t_info *info);
int				ft_put_width_str(char **coco, t_info *info);//for str or nbr
int				ft_print_nbr(unsigned long long nbr, t_info *info);
int				ft_prec_nbr(unsigned long long nbr, t_info *info, char **buf);//filling str(nbr) according prec &...
int				ft_nbrlen(unsigned long long nbr, t_info *info);
int				ft_put_sign(char **buf);//manage the neg nbr
int				ft_put_pointer_prefix(char **buf);
int				ft_putchar(char c);
int				ft_putstr(char *s);
char			*ft_baseset(char type);
#endif
