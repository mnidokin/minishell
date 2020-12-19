/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:56:09 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/19 06:01:03 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst.h"

t_dlist		*ft_dlst_new(void *data, size_t size)
{
	t_dlist	*lst;

	if (!(lst = (t_dlist*)malloc(sizeof(t_dlist))))
		return (NULL);
	lst->content = data;
	lst->size = data ? size : 0;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);	
}
