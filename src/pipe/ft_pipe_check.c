#include "minishell.h"

int	ft_pipe_check(char *cmd_line)
{
	int index;

	index = 0;
	while (cmd_line[index])
	{
		if (cmd_line[index] == '|')
			return (EXIT_SUCCESS);
		index++;
	}
	return (EXIT_FAILURE);
}
