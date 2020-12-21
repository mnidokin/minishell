/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_del_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:22:39 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/20 22:21:20 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst.h"

t_uc	ft_dlst_del_first(t_dlist *lst)
{
	if (lst)
	{
		while (lst->prev)
			lst = lst->prev;
		lst = lst->next;
		ft_dlst_del(lst->prev);
		lst->prev = NULL;
	}
	return (E_DLST_SUCCESS);
}
