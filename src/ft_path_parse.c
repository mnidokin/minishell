/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:57:16 by mnidokin          #+#    #+#             */
/*   Updated: 2020/11/20 15:18:00 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_path_parse(char **env)
{
	int		index;
	char	*str;
	char	**tmp;

	index = ft_get_env(env, "PATH", &str);
	if (index == -1)
	{
		return (NULL);
	}
	if (!(tmp = ft_strsplit(str, ':')))
		exit(2);
	free(str);
	return (tmp);
}

int		ft_fullpath_check(char *cmd, char *full_path)
{
	int index;

	index = 0;
	while (full_path[index])
	{
		if (cmd[index] != full_path[index])
			return (-1);
		index++;
	}
	return (0);
}

int		ft_get_env(char **env, char *str, char **res)
{
	int		i;
	char	**tmp;
	char	*key;

	i = 0;
	while (env[i])
	{
		if (!(key = ft_strjoin(str, "=")))
			exit(2);
		if (ft_strncmp(env[i], key, ft_strlen(key)) == 0)
		{
			if (!(tmp = ft_strsplit(env[i], '=')))
				exit(2);
			if (res)
				(*res) = ft_env_strdup(tmp[1]);
			ft_free_mattr(tmp);
			free(key);
			return (i);
		}
		free(key);
		i++;
	}
	return (-1);
}

char	*ft_env_strdup(char *tmp)
{
	char	*res;

	res = NULL;
	if (tmp)
	{
		if (!(res = ft_strdup(tmp)))
			exit(2);
	}
	else
	{
		if (!(res = ft_strdup("(null)")))
			exit(2);
	}
	return (res);
}
