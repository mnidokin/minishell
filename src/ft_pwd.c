/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:56:24 by mnidokin          #+#    #+#             */
/*   Updated: 2020/11/20 15:03:48 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_pwd(char *buf)
{
	char	*res;
	int		len;

	res = getcwd(buf, 1024);
	len = ft_strlen(res);
	if (!(res = ft_strdup(getcwd(buf, len + 1))))
		exit(2);
	return (res);
}

int		ft_builtin_pwd(void)
{
	char *pth;
	char buf[1024];

	pth = ft_pwd(buf);
	ft_putendl(pth);
	free(pth);
	return (0);
}
