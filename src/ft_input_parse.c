#include "minishell.h"

char	**ft_input_parse(char *input_str)
{
	char **res;

	res = NULL;
	res = ft_strsplit(input_str, ';');
	return (res);
}

int	ft_multiple_input(char **multiple_cmd, char ***env)
{
	int iter;
	int	res;
	int exit_stat;
	pid_t pid;

	iter = 0;
	res = 0;
	while (multiple_cmd[iter])
	{
		if ((pid = fork()) == 0)
		{
			if (ft_pipe_check(multiple_cmd[iter]) == EXIT_SUCCESS)
			{
				res = fork_pipes(multiple_cmd[iter], *env);
			}
			else
			{
				res = ft_exe(multiple_cmd[iter], env);
			}
			exit(0);
		}
		wait(&exit_stat);
		if (WIFEXITED(exit_stat))
		{
			if (WEXITSTATUS(exit_stat) != 0)
				res = -1;
		}
		iter++;
	}
	return (res);
}
