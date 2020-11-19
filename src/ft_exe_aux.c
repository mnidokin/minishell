/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:48:00 by mnidokin          #+#    #+#             */
/*   Updated: 2020/11/19 23:53:20 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_exe_chek_path(char **paths, char *cmd_prm)
{
	int			index;
	char		*res;

	index = 0;
	while (paths[index])
	{
		res = ft_exe_path_try(paths[index], cmd_prm);
		if (res)
			return (res);
		index++;
	}
	return (NULL);
}

char	*ft_exe_path_try(char *path, char *cmd_prm)
{
	char		*res;
	char		*tmp;
	struct stat	file;

	if (!ft_fullpath_check(cmd_prm, path))
		res = ft_strdup(cmd_prm);
	else
	{
		tmp = ft_strjoin("/", cmd_prm);
		res = ft_strjoin(path, tmp);
		free(tmp);
	}
	if (lstat(res, &file) == -1)
	{
		if (res)
			free(res);
	}
	else
	{
		if (file.st_mode & S_IFREG)
			if (file.st_mode & S_IXUSR)
				return (res);
	}
	return (NULL);
}
