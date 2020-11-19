#include "minishell.h"

int	ft_builtin(char **cmd, char ***env)
{
	if (ft_strequ(cmd[0], "exit"))
		return (-1);
	else if (ft_strequ(cmd[0], "setenv"))
		return (ft_builtin_setenv(cmd, env));
	else if (ft_strequ(cmd[0], "unsetenv"))
		return (ft_builtin_unsetenv(cmd, env));
	else if (ft_strequ(cmd[0], "index"))
		return (ft_test_index(*env, cmd));
	else if (ft_strequ(cmd[0], "index_num"))
		return (ft_test_index_num(*env, ft_atoi(cmd[1])));
	else if (ft_strequ(cmd[0], "env"))
		return (ft_builtin_env(*env));
	else if (ft_strequ(cmd[0], "cd"))
		return (ft_builtin_cd(cmd, env));
	else if (ft_strequ(cmd[0], "pwd"))
		return (ft_builtin_pwd());
	else if (ft_strequ(cmd[0], "echo"))
		return (ft_builtin_echo(cmd, *env));
	return (9);
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
