/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:26:09 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/19 07:20:29 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static ssize_t	ft_get_line(char **line)
{
	t_uc		ret;
	char		*tmp;
	char		buf[9];

	tmp = NULL;
	if ((ret = ft_term_init(&(g_term.fd), &(g_term.screen))))
		return (ret > 6 ? ft_term_deinit(&(g_term.fd), &(g_term.screen)) : ret);

	ft_bzero(buf, 9);
	while ((ret = read(g_term.fd.in, buf, 8)) > 0)
	{
		tmp = *line;
		if (ft_is_spec_key(buf) && ft_key_action(buf, line))
		{
			if (ft_strequ(buf, "\r"))
			{
				*line = ft_strjoin(tmp, "\n");
				break ;
			}
			ft_bzero(buf, 9);
			continue ;
		}
		else if (!(*line = ft_strjoin(tmp, buf)))
		{
			ft_term_deinit(&(g_term.fd), &(g_term.screen));
			return (-1);
		}
		ft_strdel(&tmp);
		ft_dprintf(g_term.fd.out, "%s", buf);
		ft_bzero(buf, 9);
	}
	ft_bzero(buf, 9);
	ft_term_deinit(&(g_term.fd), &(g_term.screen));
	return (ret);
}

static int		ft_strcpy_m(char **line, char *content)
{
	char	*c;
	size_t	l;

	c = NULL;
	if ((c = ft_strchr(content, '\n')))
		if ((*line = ft_strnew((c - content))))
			if ((ft_memcpy(*line, content, (c - content))))
				return ((c - content));
	if ((l = ft_strlen(content)))
		if ((*line = ft_strnew(l)))
			if ((ft_memcpy(*line, content, l)))
				return (l);
	return (0);
}

int				read_term(char **line)
{
	int		ret;
	char	**tmp;
	char	*content;

	if (!line)
		return (-1);
	if (!(content = ft_strnew(1)))
		return (-1);
	tmp = &content;
	ret = ft_get_line(tmp);
	content = *tmp;
	if (ret <= 0 && (!*tmp || !**tmp))
	{
		ft_strdel(&content);
		return (ret);
	}
	ret = ft_strcpy_m(line, content);
	ft_strdel(&content);
	return (1);
}
