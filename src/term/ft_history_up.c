/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 00:27:13 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/21 00:27:29 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void	ft_history_up(char **line)
{
	t_history	*hist;
	char		*hist_data;

	if (!(hist = ft_history(NULL)))
		return ;
	if (*line && !hist->current->content)
		ft_dlst_set_content(hist->current, (void*)(*line),
							ft_strlen(*line) + 1);
	if (hist->current->prev)
	{
		hist_data = (char*)(hist->current->prev->content);
		if (!(*line = ft_strdup(hist_data)))
			return ;
		hist->current = hist->current->prev;
	}
}
