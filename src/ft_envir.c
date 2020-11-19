/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:57:07 by mnidokin          #+#    #+#             */
/*   Updated: 2020/11/19 22:57:08 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_init(char **src, char ***env)
{
	int	i;

	i = 0;
	if (!(*env = ft_memalloc(sizeof(char *) * ft_envir_strcount(src) + 1)))
		exit(2);
	while (src[i])
	{
		if (!((*env)[i] = ft_strdup(src[i])))
			exit(2);
		i++;
	}
	(*env)[i] = NULL;
	return (0);
}

int	ft_envir_strcount(char **str)
{
	int	res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}
