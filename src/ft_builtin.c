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
		return (ft_builtin_pwd(*env));
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

int	ft_test_index(char **env, char **cmd)
{
	int abzac_pro_kvarz;
	char *res;

	res = NULL;
	abzac_pro_kvarz = ft_get_env(env, cmd[1], &res);
	ft_putendl("------------------------------");
	ft_putnbr(abzac_pro_kvarz);
	ft_putendl("");
	ft_putstr("getenv = ");
	if (getenv(cmd[1]))
		ft_putendl(getenv(cmd[1]));
	ft_putstr("ft_get_env = ");
	ft_putendl(res);
	ft_putendl("------------------------------");
	return (0);
}

int	ft_test_index_num(char **env, int index)
{
	ft_putstr("env[");
	ft_putnbr(index);
	ft_putstr("] = ");
	ft_putendl(env[index]);
	if (env[index])
		ft_putendl("true");
	else
		ft_putendl("false");
	return (0);
}
