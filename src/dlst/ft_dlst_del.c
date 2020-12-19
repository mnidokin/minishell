/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:56:14 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/19 06:04:23 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst.h"

t_uc	ft_dlst_del(t_dlist *lst)
{
	if (lst)
	{
		lst->content = NULL;
		lst->next = NULL;
		lst->prev = NULL;
		lst->size = 0;
		free(lst);
		lst = NULL;
	}
	return (E_DLST_SUCCESS);
}
