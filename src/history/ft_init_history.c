/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:10:53 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/19 22:42:08 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh_history.h"

static t_uc	fill_data_from_file(t_history *hist)
{
	char	*line;
	t_uc	err;

	hist->len = 0;
	err = SUCCESS;
	if (!(hist->current = ft_dlst_new(NULL, 0)))
		return (E_HIST_MALLOC);
	while (get_next_line(hist->fd, &line) > 0)
	{
		if ((err = hist->add(line)) != SUCCESS)
			return (err);
		ft_strdel(&line);
	}
	return (E_HIST_SUCCESS);
}

static t_uc	ft_history_add_data(char *data)
{
	t_history	*this;
	t_uc		err;

	this = ft_history(NULL);
	if (!(this->current = ft_dlst_append(this->current, NULL, 0)))
		return (E_HIST_MALLOC);
	if ((err = ft_dlst_set_content(this->current->prev, (void*)data,
									ft_strlen(data) + 1)) != E_DLST_SUCCESS)
		return (err);
	if (this->len > HIST_MAXLEN)
		ft_dlst_del_first(this->current);
	else
		++this->len;
	return (E_HIST_SUCCESS);
}

static char	*ft_history_get_data(t_uc dirrection)
{
	t_history 	*this;
	char		*res;

	this = ft_history(NULL);
	res = NULL;
	if (dirrection == HIST_UP)
		if (this->current->prev && (res = (char*)(this->current->prev->content)))
			this->current = this->current->prev;
	if (dirrection == HIST_DOWN)
		if (this->current->next && (res = (char*)(this->current->next->content)))
			this->current = this->current->prev;
	return (res);
}

static t_uc	ft_history_destroy_common(void)
{
	t_history *this;

	this = ft_history(NULL);
	return (ft_history_destroy(&this, SUCCESS));
}

t_uc	ft_init_history(void)
{
	t_history	*res;
	t_uc		err;

	err = SUCCESS;
	if (!(res = (t_history*)malloc(sizeof(t_history))))
		return (E_HIST_MALLOC);
	ft_history(&res);
	res->current = NULL;
	res->destroy = ft_history_destroy_common;
	res->add = ft_history_add_data;
	res->get = ft_history_get_data;
	if ((res->fd = open(".sh_history", O_RDONLY | O_CREAT, 0644)) < 3)
		return (ft_history_destroy(&res, E_HIST_FOERR));
	if ((err = fill_data_from_file(res)) != SUCCESS)
		return (ft_history_destroy(&res, E_HIST_DATAFILL));
	close(res->fd);
	res->fd = 0;
	return (err);
}