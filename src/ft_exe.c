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
		{
			return (-1);
		}
		i++;
	}
	return (res);
}

int	ft_exe_cmd(char **cmd_prm, char ***env)
{
	int res;

	res = 0;
	if ((ft_builtin(cmd_prm, env)) == 0)
	{
		return (0);
	}
	else
		return (-1);
	if (res == 0)
	{
		res = ft_exe_cve(cmd_prm[0] ,cmd_prm, *env);
		return (res);
	}
	return (res);
}

int	ft_exe_cve(char *cmd, char **cm_pr, char **env)
{
	if (fork() != 0)
		wait(NULL);
	if (access(cmd, 0) == 0)
	{
		if (access(cmd, 1) == 0)
		{
			execve(cmd, cm_pr, env);
			return(1);
		}
	}
	return (0);
}
