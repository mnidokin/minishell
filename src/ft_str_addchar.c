/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_addchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 01:21:50 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/21 01:21:55 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_str_addchr(char **str, char c, int len, t_us pos)
{
	char *tmp;

	if (*str && !(tmp = ft_strdup(*str)))
		exit(2);
	else if (!*str)
	{
		*str = ft_strnew(1);
		(*str)[0] = c;
		return ;
	}
	ft_strdel(&(*str));
	if (!(*str = ft_strnew(len + 1)))
		exit(2);
	ft_strncpy((*str), tmp, len);
	ft_strdel(&tmp);
	if (pos < len)
		ft_memmove(*str + pos + 1, *str + pos, len);
	(*str)[pos] = c;
}
