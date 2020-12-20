/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:22:05 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/20 22:15:39 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst.h"

t_uc	ft_dlst_clear(t_dlist *lst)
{
	while (lst->next)
		lst = lst->next;
	while (lst->prev)
	{
		lst = lst->prev;
		ft_dlst_del(lst->next);
	}
	ft_dlst_del(lst);
	lst = NULL;
	return (E_DLST_SUCCESS);
}
