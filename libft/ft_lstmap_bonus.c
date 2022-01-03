/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:15:41 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/03 18:35:58 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstnew;
	t_list	*node;

	if (!lst || !f)
		return (NULL);
	lstnew = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			if (lstnew)
			{
				ft_lstclear(&lstnew, del);
				return (NULL);
			}
		}
		ft_lstadd_back(&lstnew, node);
		lst = lst->next;
	}
	return (lstnew);
}
