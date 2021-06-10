/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:25:32 by abouhlel          #+#    #+#             */
/*   Updated: 2021/05/31 11:25:34 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*lastnode;

	if (lst == NULL || *lst == NULL)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		lastnode = tmp;
		tmp = tmp->next;
		del(lastnode->content);
		free(lastnode);
	}
	*lst = NULL;
}
