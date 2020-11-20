/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:48:00 by mnidokin          #+#    #+#             */
/*   Updated: 2020/11/20 15:10:27 by mnidokin         ###   ########.fr       */
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
	struct stat	file;

	if (!ft_fullpath_check(cmd_prm, path))
	{
		if (!(res = ft_strdup(cmd_prm)))
			exit(2);
	}
	else
		res = ft_exe_pathjoin(path, cmd_prm);
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

char	*ft_exe_pathjoin(char *path, char *cmd_prm)
{
	char	*tmp;
	char	*res;

	if (!(tmp = ft_strjoin("/", cmd_prm)))
		exit(2);
	if (!(res = ft_strjoin(path, tmp)))
		exit(2);
	free(tmp);
	return (res);
}
