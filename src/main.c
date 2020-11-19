#include "minishell.h"

int	main(int ac, char **av, char *envp[])
{
	char 	**env;
	char	*str;
	int		brake_point;

	(void)av;
	(void)ac;
	brake_point = 0;
	env = NULL;
	ft_env_init(envp, &env);
	while (1)
	{
		ft_prompt();
		ft_cmd_read(&str);
		if (!str)
		{
			ft_putstr("");
			continue ;
		}
		if ((brake_point = ft_exe(str, &env)) == -1)
		{
			free(str);
			break ;
		}
		free(str);
	}
	ft_free_mattr(env);
	return (0);
}
