/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:56:39 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/21 17:24:30 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_builtin_cd(char **cmd, char ***env)
{
	char	*home_pth;
	int		res;

	cmd += 1;
	if (!cmd[0] || ft_strequ(cmd[0], "--"))
	{
		ft_get_env(*env, "HOME", &home_pth);
		res = ft_ch_dr(home_pth, env);
		free(home_pth);
		return (res);
	}
	else if (cmd[0][0] == '-' && !cmd[0][1])
		return (ft_cd_home(env));
	else if (cmd[0][0] == '~')
		return (ft_cd_tilda(env, cmd));
	else
		return (ft_ch_dr(*cmd, env));
	return (0);
}

int		ft_ch_dr(char *pth, char ***env)
{
	char	*path_src;
	int		chdir_res;
	char	buf[1024];
	char	*path_dest;

	chdir_res = -1;
	path_src = (ft_pwd(buf));
	chdir_res = chdir(pth);
	if (chdir_res == -1)
		ft_cd_error(pth);
	else if (chdir_res == 0)
	{
		path_dest = (ft_pwd(buf));
		ft_set_pwd(env, "OLDPWD", path_src);
		ft_set_pwd(env, "PWD", path_dest);
		free(path_dest);
	}
	free(path_src);
	return (0);
}

void	ft_cd_error(char *pth)
{
	ft_putstr("cd: ");
	if (access(pth, 0) < 0)
		ft_putstr_fd("no such file or directory: ", 2);
	else if (access(pth, 1) < 0)
		ft_putstr_fd("permission denied: ", 2);
	else
		ft_putstr_fd("not a directory: ", 2);
	ft_putendl_fd(pth, 2);
}

int		ft_set_pwd(char ***env, char *env_name, char *pth)
{
	char	*tmp;
	char	*res;
	int		index;

	tmp = NULL;
	res = NULL;
	index = ft_get_env(*env, env_name, NULL);
	if (!(tmp = ft_strjoin(env_name, "=")))
		exit(2);
	if (!(res = ft_strjoin(tmp, pth)))
		exit(2);
	if ((*env)[index])
	{
		free((*env)[index]);
		if (!((*env)[index] = ft_strdup(res)))
			exit(2);
	}
	free(tmp);
	free(res);
	return (0);
}

char	*ft_cd_homereplace(char *cmd, char *home_path)
{
	char *res;

	if (!(res = ft_strjoin(home_path, &cmd[1])))
		exit(2);
	return (res);
}
