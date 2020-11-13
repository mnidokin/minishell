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

	/*char **str_1;
	str_1 = ft_memalloc(sizeof(char *) * 5);
	for(int i = 0; i < 4; i++)
	{
		str_1[i] = ft_strdup("JOPA");
	}
	str_1[4] = NULL;
	int i = 0;
	while (str_1[i])
	{
		ft_putendl(str_1[i]);
		i++;
	}
	str_1 = ft_unsetenv_suppress(str_1);
	ft_putendl("------------");
	i = 0;
	while (str_1[i])
	{
		ft_putendl(str_1[i]);
		i++;
	}
	return (0);*/
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
