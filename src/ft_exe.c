/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:56:05 by mnidokin          #+#    #+#             */
/*   Updated: 2020/11/19 23:48:44 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_exe(char *str, char ***env)
{
	char	**cmd_prm;
	int		res;
	int		i;

	res = 0;
	i = 0;
	if (!(cmd_prm = ft_cmd_split(str)))
		exit(2);
	res = ft_exe_cmd(cmd_prm, env);
	if (res == -1)
	{
		ft_free_mattr(cmd_prm);
		return (-1);
	}
	ft_free_mattr(cmd_prm);
	return (res);
}

int		ft_exe_cmd(char **cmd_prm, char ***env)
{
	int			res;

	if (!cmd_prm[0])
		return (0);
	res = -999;
	if ((res = ft_builtin(cmd_prm, env)) == 0)
		return (0);
	else if (res == -1)
		return (-1);
	if (res == 9)
		res = ft_exe_notbuiltin(env, cmd_prm, res);
	if (res == 9)
	{
		ft_putstr("minishell: command not found: ");
		ft_putendl(cmd_prm[0]);
	}
	return (res);
}

int		ft_exe_notbuiltin(char ***env, char **cmd_prm, int res)
{
	char		**path;
	char		*path_to_exe;
	struct stat	file;

	path = NULL;
	path = ft_path_parse(*env);
	if (path && (path_to_exe = ft_exe_chek_path(path, cmd_prm[0])) != NULL)
	{
		res = ft_exe_cve(path_to_exe, cmd_prm, *env);
		free(path_to_exe);
	}
	else
	{
		if (lstat(cmd_prm[0], &file) != -1)
		{
			if (file.st_mode & S_IFREG)
				if (file.st_mode & S_IXUSR)
					res = ft_exe_cve(cmd_prm[0], cmd_prm, *env);
		}
	}
	if (path)
		ft_free_mattr(path);
	return (res);
}

int		ft_exe_cve(char *cmd, char **cm_pr, char **env)
{
	pid_t	pid;

	if ((pid = fork()) == 0)
	{
		if (access(cmd, 0) == 0)
			if (access(cmd, 1) == 0)
				execve(cmd, cm_pr, env);
	}
	else if (pid < 0)
		return (-1);
	wait(&pid);
	return (0);
}
