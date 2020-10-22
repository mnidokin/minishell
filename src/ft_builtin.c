#include "minishell.h"

int	ft_builtin(char *cmd)
{
	if (ft_strequ(cmd, "exit"))
		return (-1);
	return (0);
}