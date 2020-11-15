#include "minishell.h"

void	test(char **env)
{
	env = ft_setenv_expand(env);
}

int	main(int ac, char **av, char *envp[])
{
	t_envir	*envir;
	char 	**env;
	char	*str;
	int		brake_point;

	(void)av;
	(void)ac;
	brake_point = 0;
	env = NULL;
	envir = ft_envir_lst(envp, &env);
	while (1)
	{
		ft_prompt();
		ft_cmd_read(&str);
		if (!str)
			ft_putstr("");
		if ((brake_point = ft_exe(str, envir, &env)) == -1)
			exit (0);
	}
	return (0);
}
