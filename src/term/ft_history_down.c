/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 00:25:45 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/21 00:25:47 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void	ft_history_down(char **line)
{
	t_history	*hist;
	char		*hist_data;

	if (!(hist = ft_history(NULL)))
		return ;
	if (hist->current->next && hist->current->next->content)
	{
		hist_data = (char*)(hist->current->next->content);
		if (!(*line = ft_strdup(hist_data)))
			return ;
		hist->current = hist->current->next;
	}
	else if (hist->current->next)
	{
		*line = NULL;
		hist->current = hist->current->next;
	}
}
