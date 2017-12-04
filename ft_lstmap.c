/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:05:55 by lapain            #+#    #+#             */
/*   Updated: 2017/12/04 21:57:57 by lapain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *new_list;

	if (!lst)
		return (NULL);
	if (!(tmp = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	tmp = f(lst);
	new_list = tmp;
	while (lst->next)
	{
		new_list->next = f(lst->next);
		new_list = new_list->next;
		lst = lst->next;
	}
	return (tmp);
}
