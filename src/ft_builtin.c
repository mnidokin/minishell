#include "minishell.h"

int	ft_builtin(char **cmd, char **env)
{
	if (ft_strequ(cmd[0], "exit"))
		return (-1);
	else if (ft_strequ(cmd[0], "env"))
		return (ft_builtin_env(env));
	else if (ft_strequ(cmd[0], "setenv"))
		return (ft_builtin_setenv(cmd, env));
	return (0);
}

int	ft_builtin_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
	return (0);
}
