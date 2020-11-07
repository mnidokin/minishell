#include "minishell.h"

int	ft_builtin_setenv(char **cmd, char ***env)
{
	if (!cmd[1])
		return (ft_builtin_env(*env));
	if (cmd[1] && cmd[2] && cmd[3])
	{
		ft_putendl_fd("setenv: too many arguments", 2);
		return (0);
	}
	else
	{
		ft_setenv(cmd, env);
		return (0);
	}
	return (-1);
}

int	ft_setenv(char **cmd, char ***env)
{
	int		index;

	index = 0;
	index = ft_get_env(*env, cmd[1], NULL);
	if (cmd[2])
	{
		*env = ft_setenv_value(cmd, index, *env);
	}
	else
		*env = ft_setenv_nonvalue(cmd, index, *env);
	return (0);
}

char **ft_setenv_value(char **cmd, int index, char **env)
{
	char	*tmp;
	char	*str;

	tmp = NULL;
	if (!(tmp = ft_strjoin(cmd[1], "=")))
		exit(2);
	if (!(str = ft_strjoin(tmp, cmd[2])))
		exit(2);
	if (env[index])
	{
		free(env[index]);
		if (!(env[index] = ft_strdup(str)))
			exit(2);
	}
	else
	{
		env = ft_setenv_expand(env);
		if (!(env[index] = ft_strdup(str)))
			exit(2);
		env[index + 1] = NULL;
	}
	free(tmp);
	free(str);
	return (env);
}

char	**ft_setenv_nonvalue(char **cmd, int index, char **env)
{
	char *tmp;

	if (!(tmp = ft_strjoin(cmd[1], "=")))
		exit(2);
	if (env[index])
	{
		free(env[index]);
		if (!(env[index] = ft_strdup(tmp)))
			exit(2);
	}
	else
	{
		env = ft_setenv_expand(env);
		if (!(env[index] = ft_strdup(tmp)))
			exit(2);
	}
	free(tmp);
	return (env);
}

char **ft_setenv_expand(char **env)
{
	char	**res;
	int		size;
	int		i;

	i = 0;
	size = ft_envir_strcount(env) + 1;
	if (!(res = ft_memalloc(sizeof(char *) * size)))
		exit(2);
	while ((env)[i])
	{
		if (!(res[i] = ft_strdup((env)[i])))
			exit(2);
		//free(env[i]);
		i++;
	}
	//free(env);
	return (res);
}
