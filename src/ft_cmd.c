/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:56:49 by mnidokin          #+#    #+#             */
/*   Updated: 2020/11/20 15:01:46 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cmd_read(char **cmd)
{
	int		len;
	char	c;

	len = 0;
	while (1)
	{
		if (!(read(0, &c, 1)))
			break ;
		if (c == '\n' && len == 0)
		{
			*cmd = NULL;
			break ;
		}
		if (c == '\n' && len > 0)
			break ;
		if (len > 0)
			ft_str_addchr(cmd, c, len);
		else
		{
			*cmd = ft_strnew(len + 1);
			*cmd[len] = c;
		}
		len++;
	}
}

void	ft_str_addchr(char **str, char c, int len)
{
	char *tmp;

	if (!(tmp = ft_strdup(*str)))
		exit(2);
	ft_strdel(&(*str));
	if (!(*str = ft_strnew(len + 1)))
		exit(2);
	ft_strncpy((*str), tmp, len);
	ft_strdel(&tmp);
	(*str)[len] = c;
}
