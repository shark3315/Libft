/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:19:41 by lapain            #+#    #+#             */
/*   Updated: 2017/12/04 20:48:38 by lapain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list *tmp;

	tmp = *alst;
	while (tmp != NULL)
	{
		del((tmp)->content, (tmp)->content_size);
		free(tmp);
		tmp = tmp->next;
	}
	*alst = NULL;
}
