/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clipboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 03:50:00 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/26 05:07:07 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static char		*get(void)
{
	return ((ft_clipboard())->line);
}

static t_uc		set(char *start, char *end)
{
	t_clip	*this;
	size_t	len;

	if (!(this = ft_clipboard()))
		return (FAIL);
	if (this->line)
		ft_strdel(&(this->line));
	len = end && end > start ? end - start : ft_strlen(start);
	if (!(this->line = ft_strndup(start, len)))
		return (FAIL);

	return (SUCCESS);
}

static void		*destroy(void)
{
	t_clip	*this;

	this = ft_clipboard();
	this->get = NULL;
	this->set = NULL;
	this->destroy = NULL;
	if (this->line)
		ft_strdel(&(this->line));
	free(this);
	this = NULL;
	return (NULL);
}

static t_clip	*new_clipboard(void)
{
	t_clip	*clipboard;

	if (!(clipboard = (t_clip*)malloc(sizeof(t_clip))))
		return (NULL);
	clipboard->get = get;
	clipboard->set = set;
	clipboard->destroy = destroy;
	clipboard->line = NULL;
	return (clipboard);
}

t_clip			*ft_clipboard(void)
{
	static t_clip	*clipboard = NULL;

	if (!clipboard)
		clipboard = new_clipboard();
	return (clipboard);
}