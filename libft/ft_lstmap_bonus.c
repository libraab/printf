/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:26:34 by abouhlel          #+#    #+#             */
/*   Updated: 2021/05/31 11:26:37 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newelment;
	t_list	*newlist;

	if (!lst || !f)
		return (NULL);
	newlist = NULL;
	while (lst != NULL)
	{
		newelment = ft_lstnew(f(lst->content));
		if (!newelment)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newelment);
		lst = lst->next;
	}
	return (newlist);
}
