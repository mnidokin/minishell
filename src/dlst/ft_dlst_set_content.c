/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_set_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 22:42:57 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/19 22:46:34 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst.h"

t_uc	ft_dlst_set_content(t_dlist *lst, void *data, size_t size)
{
	lst->content = ft_memdup(data, size);
	lst->size = lst->content ? size : 0;
	if (lst->content)
		return (E_DLST_SUCCESS);
	return (E_DLST_MALLOC);
}