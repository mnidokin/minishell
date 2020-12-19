/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_save.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 06:36:43 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/19 23:05:01 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh_history.h"

t_uc	ft_history_save(void)
{
	t_history	*history;
	t_dlist		*data;
	int			fd;

	history = ft_history(NULL);
	if (!history)
		return (E_HIST_NO);
	if (!(data = history->current->prev))
		return (E_HIST_SUCCESS);
	if (history->len < HIST_MAXLEN)
	{
		if ((fd = open(".sh_history", O_WRONLY | O_APPEND)) < 3)
			return (E_HIST_FOERR);
		ft_dprintf(fd, "%s\n", (char*)(data->content));
	}
	else
	{
		if ((fd = open(".sh_history", O_WRONLY)) < 3)
			return (E_HIST_FOERR);
		while (data->prev)
			data = data->prev;
		while (data && data->content)
		{
			ft_dprintf(fd, "%s\n", (char*)(data->content));
			data = data->next;
		}
	}
	close(fd);
	return (E_HIST_SUCCESS);
}
