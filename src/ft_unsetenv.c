#include "minishell.h"

int		ft_builtin_unsetenv(char **cmd, char **env)
{
	int	index;

	if (!cmd[1])
		ft_putendl_fd("unsetenv: too few arg", 2);
	else
	{
		index = ft_get_env(env,  cmd[1], NULL);
		return (ft_unsetenv(index, &env));
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
	j = ++index;
	while ((*env)[j])
	{
		if ((*env)[i])
			free((*env)[i]);
		(*env)[i] = ft_strdup((*env)[j]);
		i++;
		j++;
	}
	ft_unsetenv_suppress(env);
	return (0);
}

char	**ft_unsetenv_suppress(char ***env)
{
	char	**res;
	int		size;
	int		index;

	index = 0;
	size = ft_envir_strcount((*env));
	if (!(res = ft_memalloc(sizeof(char *) * size)))
		exit(2);
	while ((*env)[index])
	{
		if (!(res[index] = ft_strdup((*env)[index])))
			exit(2);
		free((*env)[index]);
		index++;
	}
	return (res);
}
