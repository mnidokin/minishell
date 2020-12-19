/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:10:51 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/19 06:44:59 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh_history.h"

t_uc	ft_history_destroy(t_history **hist, t_uc err)
{
	(*hist)->add = NULL;
	(*hist)->get = NULL;
	(*hist)->destroy = NULL;
	ft_dlst_clear((*hist)->data);
	(*hist)->data = NULL;
	if ((*hist)->fd > 2)
		close((*hist)->fd);
	(*hist)->fd = 0;
	(*hist)->len = 0;
	free(*hist);
	*hist = NULL;
	return (err);
}