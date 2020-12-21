#include "minishell.h"

int spawn_proc (int in, int out, char *cmd, char **env)
{
	int res;
	pid_t pid;
	
	res = 0;
	if ((pid = fork()) == 0)
	{
		if (in != 0)
		{
			dup2 (in, 0);
			close (in);
		}
		if (out != 1)
		{
			dup2 (out, 1);
			close (out);
		}
		char **cmd_prm = ft_cmd_split(cmd);
		res = ft_exe_notbuiltin(&env, cmd_prm, res);
	}
	else if (pid < 0)
		return (-1);
	wait(&pid);
	return (res);
}

int	fork_pipes (char *cmd, char **env)
{
  int i;
  int val_num;
  int in, fd [2];
  int res;
  char **cmd_pipes;

  in = 0;
  res = 0;
  cmd_pipes = ft_strsplit(cmd, '|');
  val_num = ft_pipe_arg_num(cmd_pipes);
  for (i = 0; i < val_num - 1; ++i)
    {
      pipe (fd);
      spawn_proc(in, fd[1], cmd_pipes[i], env);
      close (fd[1]);
      in = fd[0];
    }
	if (in != 0)
		dup2 (in, 0);
	res = ft_exe(cmd_pipes[i], &env);
	return (res);
}

int	ft_pipe_arg_num(char **pipe_ar)
{
	int res;

	res = 0;
	if (pipe_ar != NULL)
	{
		while (*pipe_ar)
		{
			res++;
			pipe_ar++;
		}
		return (res);
	}
	return (res);
}
