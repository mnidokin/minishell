#include "minishell.h"

int	main(int ac, char **av)
{
	extern char		**environ;
	char			**env_var;

	ft_envir_arr(environ, env_var);
	for(int i = 0; env_var != NULL; i++)
	{
		ft_putstr(env_var[i]);
		ft_putchar('\n');
	}

	return (0);
}
