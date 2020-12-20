/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:56:27 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/20 20:35:45 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sighandler(int sig)
{
	if (g_pid)
		kill(g_pid, sig);
}

void	ft_siginit(void)
{
	t_uc i;

	i = 0;
	g_pid = 0;
	while (i++ < SIGUSR2)
		signal(i, sighandler);	
}

int	main(int ac, char **av, char *envp[])
{
	char	**env;
	char	*str;
	char	**multiple_input;
	int		brake_point;

	(void)av;
	(void)ac;
	brake_point = 0;
	env = NULL;
	ft_env_init(envp, &env);
	ft_init_history();
	ft_siginit();
	while (1)
	{
		ft_prompt();
		ft_cmd_read(&str);
		if (!str)
		{
			ft_putstr("");
			continue ;
		}
		multiple_input = ft_input_parse(str);
		if (ft_multiple_input(multiple_input, &env) == -1)
			break ;
		ft_strdel(&str);
	}
	ft_strdel(&str);
	ft_free_mattr(env);
	return (0);
}
