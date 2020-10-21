#include "minishell.h"

int	ft_exe(char *str, t_envir *environ)
{
	char	**commands;
	char	**cmd_prm;

	(void)environ;
	if (!(commands = ft_strsplit(str, ';')))
		exit(2);
	while (*commands)
	{
		if (!(cmd_prm = ft_cmd_split(*commands)))
			exit(2);
		ft_exe_cmd(cmd_prm);
		commands++;
	}
	return (0);
}

int	ft_exe_cmd(char **cmd_prm)
{
	if (fork() > 0)
		wait(NULL);
	else
		execve(cmd_prm[0], cmd_prm, g_env);
	return (0);
}
