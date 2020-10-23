#include "minishell.h"

int	ft_exe(char *str, t_envir *environ)
{
	char	**commands;
	char	**cmd_prm;
	int		res;

	(void)environ;
	res = 0;
	if (!(commands = ft_strsplit(str, ';')))
		exit(2);
	while (*commands)
	{
		if (!(cmd_prm = ft_cmd_split(*commands)))
			exit(2);
		res = ft_exe_cmd(cmd_prm);
		if (res == -1)
			break ;
		commands++;
	}
	return (res);
}

int	ft_exe_cmd(char **cmd_prm)
{
	int res;

	res = 0;
	if ((res = ft_builtin(cmd_prm[0])) < 0)
		return (-1);
	else if (res == 0 | )
	/*else
		res = ft_exe_cve(cmd_prm);*/
	return (res);
}

int	ft_exe_cve(char *cmd, char **cm_pr)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_putendl("Fork failed to create a new process.");
		return (-1);
	}
	else if (pid > 0)
		wait(NULL);
	else
		execve(cmd, cm_pr, g_env);
	return (1);
}
