/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 21:16:30 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/20 22:25:28 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh_history.h"

t_history	*ft_history(t_history **initial_history)
{
	static	t_history *history = NULL;

	if (initial_history)
	{
		if (*initial_history)
			history = *initial_history;
		else
			*initial_history = history;
	}
	return (history);
}
