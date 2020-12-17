/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:56:27 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/15 13:11:42 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		free(str);
	}
	free(str);
	ft_free_mattr(env);
	return (0);
}
