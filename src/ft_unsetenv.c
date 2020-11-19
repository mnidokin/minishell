/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:56:19 by mnidokin          #+#    #+#             */
/*   Updated: 2020/11/19 22:56:21 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_builtin_unsetenv(char **cmd, char ***env)
{
	int	index_env;

	if (!cmd[1])
	{
		ft_putendl_fd("unsetenv: Too few arguments", 2);
		return (0);
	}
	index_env = ft_get_env(*env, cmd[1], NULL);
	if (index_env != -1 && (*env)[index_env])
	{
		return (ft_remove_var(index_env, env));
	}
	return (1);
}

int		ft_remove_var(int index, char ***env)
{
	int i;
	int	str_count;

	if ((*env)[index])
		free((*env)[index]);
	(*env)[index] = NULL;
	i = index;
	str_count = index + 1;
	while ((*env)[i + 1])
	{
		if ((*env)[i])
		{
			free((*env)[i]);
			(*env)[i] = NULL;
		}
		if (!((*env)[i] = ft_strdup((*env)[i + 1])))
			exit(2);
		i++;
		str_count++;
	}
	str_count -= 1;
	(*env) = ft_env_realloc(str_count, env);
	return (0);
}

char	**ft_env_realloc(int size, char ***env)
{
	char	**res;
	int		i;

	if (!(res = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		exit(2);
	i = 0;
	while ((*env)[i] && i < size)
	{
		if (!(res[i] = ft_strdup((*env)[i])))
			exit(2);
		free((*env)[i]);
		i++;
	}
	free((*env)[i]);
	free(*env);
	return (res);
}
