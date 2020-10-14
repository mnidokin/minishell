#include "minishell.h"

extern char		**environ;

int	main(int ac, char **av)
{
	t_envir	*envir;
	char	*cmd;

	(void)ac;
	(void)av;
	envir = ft_envir_lst(environ);
	(void)envir;
	while (1)
	{
		ft_prompt();
		ft_cmd_read(&cmd);
		
	}
	
	/*while (envir)
	{
		if (!ft_strcmp(envir->name, "PWD"))
		{
			ft_putstr(envir->name);
			ft_putchar('=');
			ft_putstr(envir->value);
			ft_putchar('\n');
		}
		envir = envir->next;
	}*/
	//ft_free(&envir);
	return (0);
}
