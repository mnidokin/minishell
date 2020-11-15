#include "minishell.h"

int	ft_builtin_cd(char **cmd, char ***env)
{
	char *home_pth;

	cmd += 1;
	ft_get_env(*env, "HOME", &home_pth);
	if (!cmd[0] || ft_strequ(cmd[0], "--"))
		return (ft_ch_dr(home_pth, env));
	else if (cmd[0][0] == '-' && !cmd[0][1])
	{
		ft_get_env(*env, "OLDPWD", &home_pth);
		return (ft_ch_dr(home_pth, env));
	}
	else if (cmd[0][0] == '~')
	{
		home_pth = ft_cd_homereplace(cmd[0], *env);
		return (ft_ch_dr(home_pth, env));
	}
	else
		return(ft_ch_dr(*cmd, env));
	return (0);
}

int ft_ch_dr(char *pth, char ***env)
{
	char *cwd;
	int	chdir_res;
	char buf[5121];

	chdir_res = -1;
	cwd = getcwd(buf, 5120);
	chdir_res = chdir(pth);
	if (chdir_res == -1)
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
	else if (chdir_res == 0)
	{
		ft_set_pwd(env, "OLDPWD", cwd);
		ft_set_pwd(env, "PWD", ft_pwd(NULL));
	}
	return (0);
}

int	ft_set_pwd(char ***env, char *env_name, char *pth)
{
	char *tmp;
	char *res;
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

char *ft_cd_homereplace(char *cmd, char **env)
{
	int	iter;
	char **path_matr;
	char *home_path;
	char *res;
	char *tmp;

	iter = 0;
	res = NULL;
	path_matr = ft_strsplit(cmd, '/');
	ft_get_env(env, "HOME", &home_path);
	free(path_matr[0]);
	path_matr[0] = ft_strdup(home_path);
	while (path_matr[iter])
	{
		tmp = ft_strjoin(path_matr[iter], "/");
		res = ft_strjoin(res, tmp);
		free(tmp);
		iter++;
	}
	return (res);
}
