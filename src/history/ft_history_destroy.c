/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:10:51 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/20 23:56:09 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh_history.h"

t_uc	ft_history_destroy(t_history **hist, t_uc err)
{
	(*hist)->add = NULL;
	(*hist)->get = NULL;
	(*hist)->destroy = NULL;
	ft_dlst_clear((*hist)->current);
	(*hist)->current = NULL;
	if ((*hist)->fd > 2)
		close((*hist)->fd);
	(*hist)->fd = 0;
	(*hist)->len = 0;
	free(*hist);
	*hist = NULL;
	return (err);
}
