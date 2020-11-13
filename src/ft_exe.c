#include "minishell.h"

int	ft_exe(char *str, t_envir *environ, char ***env)
{
	char	**commands;
	char	**cmd_prm;
	int		res;
	int		i;

	(void)environ;
	res = 0;
	i = 0;
	if (!(commands = ft_strsplit(str, ';')))
		exit(2);
	while (commands[i])
	{
		if (!(cmd_prm = ft_cmd_split(*commands)))
			exit(2);
		res = ft_exe_cmd(cmd_prm, env);
		if (res == -1)
			return (-1);
		i++;
	}
	return (res);
}

int	ft_exe_cmd(char **cmd_prm, char ***env)
{
	int res;
	char **path;
	char *path_to_exe;

	res = 0;
	if ((res = ft_builtin(cmd_prm, env)) == 0)
		return (0);
	else if (res == -1)
		return (-1);
	if (res == 9)
	{
		path = ft_path_parse(*env);
		if ((path_to_exe = ft_exe_chek_path(path, cmd_prm[0])) != NULL)
			res = ft_exe_cve(path_to_exe, cmd_prm, *env);
	}
	if (res == 9)
	{
		ft_putstr("minishell: command not found: ");
		ft_putendl(cmd_prm[0]);
	}
	return (res);
}

int	ft_exe_cve(char *cmd, char **cm_pr, char **env)
{
	pid_t	pid;

	if((pid = fork()) == 0)
	{
		if (access(cmd, 0) == 0)
		{
			if (access(cmd, 1) == 0)
			{
				execve(cmd, cm_pr, env);
			}
		}
	}
	else if (pid < 0)
	{
		return (-1);
	}
	wait(&pid);
	return (0);
}

char *ft_exe_chek_path(char **paths, char *cmd_prm)
{
	int index;
	char *res;
	char *tmp;
	struct stat file;

	index = 0;
	res = NULL;
	tmp = NULL;
	while (paths[index])
	{
		if (!ft_fullpath_check(cmd_prm, paths[index]))
		{
			res = ft_strdup(cmd_prm);
		}
		else
		{
			tmp = ft_strjoin("/", cmd_prm);
			res = ft_strjoin(paths[index], tmp);
		}
		if (lstat(res, &file) == -1)
		{
			if (res)
			{
				free(res);
			}
		}
		else 
		{
			free(tmp);
			if (file.st_mode & S_IFREG)
			{
				if (file.st_mode & S_IXUSR)
				{
					return (res);
				}
			}
		}
		index++;
	}
	free(tmp);
	return (NULL);
}
