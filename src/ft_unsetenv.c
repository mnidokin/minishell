#include "minishell.h"

static char **ft_env_realloc(int size, char ***env)
{
	char **res;
	int i;

	res = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	i = 0;
	while((*env)[i] && i < size)
	{
		res[i] = ft_strdup((*env)[i]);
		free((*env)[i]);
		i++;
	}
	free(*env);
	return (res);
}

static void	ft_remove_var(int index, char ***env)
{
	int i;
	int	str_count;

	free((*env)[index]);
	(*env)[index] = NULL;
	i = index;
	str_count = index + 1;
	while ((*env)[i + 1])
	{
		if ((*env)[i])
		{
			free((*env)[i]);
			(*env)[i] = NULL;
		}
		(*env)[i] = ft_strdup((*env)[i + 1]);
		i++;
		str_count++;
	}
	(*env) = ft_env_realloc(str_count - 1, env);
}

int	ft_builtin_unsetenv(char **cmd, char ***env)
{
	int	index_env;

	if (!cmd[0])
	{
		ft_putendl_fd("unsetenv: Too few arguments", 2);
		return (0);
	}
	index_env = ft_get_env(*env, cmd[1], NULL);
	if ((*env)[index_env])
	{
		ft_remove_var(index_env, env);
	}
	return (0);
}

/*
int		ft_builtin_unsetenv(char **cmd, char ***env)
{
	int	index;

	if (!cmd[1])
		ft_putendl_fd("unsetenv: too few arg", 2);
	else
	{
		index = ft_get_env((*env),  cmd[1], NULL);
		return (ft_unsetenv(index, env));
	}
	return (1);
}

int		ft_unsetenv(int	index, char ***env)
{
	int i;
	int j;

	if ((*env)[index])
	{
		free((*env)[index]);
		(*env)[index] = NULL;
	}
	i = index;
	j = index + 1;
	while ((*env)[j])
	{
		if ((*env)[i])
			free((*env)[i]);
		(*env)[i] = ft_strdup((*env)[j]);
		i++;
		j++;
	}
	ft_unsetenv_suppress(*env);
	return (0);
}

char	**ft_unsetenv_suppress(char **env)
{
	char	**res;
	int		size;
	int		index;

	index = 0;
	size = ft_envir_strcount(env);
	ft_putendl("JOPA");
	if (!(res = ft_memalloc(sizeof(char *) * size)))
		exit(2);
	while (env[index + 1])
	{
		if (!(res[index] = ft_strdup(env[index])))
			exit(2);
		free(env[index]);
		index++;
	}
	return (res);
}
*/


