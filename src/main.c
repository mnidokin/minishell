#include "minishell.h"

int	main(int ac, char **av, char *envp[])
{
	t_envir	*envir;
	char 	**env;
	char	*str;

	(void)av;
	(void)ac;
	env = NULL;
	envir = ft_envir_lst(envp, &env);
	while (1)
	{
		ft_prompt();
		ft_cmd_read(&str);
		if (!str)
			ft_putstr("");
		else if (ft_exe(str, envir, env) == -1)
			break ;
	}
	return (0);
}
