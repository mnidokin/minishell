#include "minishell.h"

int	ft_exe(char *str, t_envir *environ)
{
	char		**cmd_arr;
	char		*cmd_path;
	struct stat	file;

	(void)environ;
	if (!(cmd_arr = ft_strsplit(str, ';')))
		exit(2);
	if (lstat(*cmd_arr, &file))
	{
		if (file.st_mode & S_IXUSR)
		{
			if (!(cmd_path = ft_strdup(*cmd_arr)))
				exit(2);
			return (ft_exe_cmdrun(cmd_arr, cmd_path));
		}
	}
	return (0);
}

int	ft_exe_cmdrun(char **cmd, char *path)
{
	pid_t pid;

	(void)cmd;
	(void)path;
	pid = fork();
	return (0);
}
