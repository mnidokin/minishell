#include "minishell.h"

int	ft_pipe(char *cmd_line, char **env)
{
	int		res;
	char	**pipe_ar;

	pipe_ar = ft_strsplit(cmd_line, '|');
	res = ft_pipe_subproc_gen(pipe_ar, env);
	return (res);
}

int	ft_pipe_subproc_gen(char **pipe_ar, char **env)
{
	int		fd[2];
	int		in_fd;
	char	**cmd_prm;

	pipe(fd);
	in_fd = 0;
	ft_pipe_exe(pipe_ar[0], env, in_fd, fd[1]);
	close(fd[1]);
	in_fd = fd[0];
	if (in_fd != 0)
		dup2(in_fd, 0);
	return (ft_exe(pipe_ar[1], &env));
}

int	ft_pipe_exe(char *cmd, char **env, int fd_in, int fd_out)
{
	pid_t	pid;

	if ((pid = fork()) == 0)
	{
		if (fd_in != 0)
		{
			dup2(fd_in, 0);
			close(fd_in);
		}
		if (fd_out != 1)
		{
			dup2(fd_out, 1);
			close(fd_out);
		}
		ft_exe(cmd, &env);
		exit(0);
	}
}
