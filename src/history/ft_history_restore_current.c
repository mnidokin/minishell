/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_restore_current.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 05:45:46 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/30 05:45:49 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh_history.h"

t_uc	ft_history_restore_current(void)
{
	t_history *history;

	if (!(history = ft_history(NULL)))
		return (FAIL);
	while (history->current->next)
		history->current = history->current->next;
	return(SUCCESS);
}
