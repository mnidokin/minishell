#include "minishell.h"

extern char		**environ;

int	main(int ac, char **av)
{
	t_envir	*envir;
	char	*str;

	(void)av;
	(void)ac;
	envir = ft_envir_lst(environ);
	while (1)
	{
		ft_prompt();
		ft_cmd_read(&str);
		ft_exe(str, envir);
	}
	return (0);
}
