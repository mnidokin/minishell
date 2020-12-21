/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:56:27 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/21 20:22:10 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		sighandler(int sig)
{
	if (g_pid)
		kill(g_pid, sig);
}

void		ft_siginit(void)
{
	t_uc i;

	i = 0;
	g_pid = 0;
	while (i++ < SIGUSR2)
		signal(i, sighandler);
}

static char	**init(char *envp[])
{
	char	**env;

	env = NULL;
	ft_env_init(envp, &env);
	ft_init_history();
	ft_siginit();
	return (env);
}

int			main(int ac, char **av, char *envp[])
{
	char	**env;
	char	*str;
	char	**multiple_input;

	(void)av;
	(void)ac;
	env = init(envp);
	while (1)
	{
		ft_promt(env);
		ft_cmd_read(&str);
		if (str)
		{
			multiple_input = ft_input_parse(str);
			if (ft_multiple_input(multiple_input, &env) == -1)
				break ;
			ft_strdel(&str);
		}
		else
			ft_putstr("");
	}
	ft_strdel(&str);
	ft_free_mattr(env);
	return (0);
}
