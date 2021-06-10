/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:26:03 by abouhlel          #+#    #+#             */
/*   Updated: 2021/05/31 11:26:08 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//repete sur la liste lst et applique la fonction f
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return ;
	tmp = lst;
	while (tmp->next != NULL)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
	f(tmp->content);
}
