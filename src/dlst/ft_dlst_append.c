/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:22:34 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/19 06:57:16 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst.h"

t_dlist	*ft_dlst_append(t_dlist *lst, void *data, size_t size)
{
	t_dlist *new;

	if (!(new = ft_dlst_new(data, size)))
		return (NULL);
	if (!lst)
		return (new);
	while (lst->next)
		lst = lst->next;
	lst->next = new;
	new->prev = lst;
	return (lst->next);
}
