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
		if (!str)
			ft_putstr("");
		else if (ft_exe(str, envir) & (ft_strcmp(str, "\n") != 0))
			break ;
	}
	return (0);
}
