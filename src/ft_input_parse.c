/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 22:27:19 by mozzart           #+#    #+#             */
/*   Updated: 2021/02/03 19:10:07 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_input_parse(char *input_str)
{
	char **res;

	res = NULL;
	res = ft_strsplit(input_str, ';');
	return (res);
}

int		ft_multiple_input(char **multiple_cmd, char ***env)
{
	int iter;
	int	res;
	int exit_stat;
	char	**cmd_prm;
	pid_t pid;

	iter = 0;
	res = 0;
	while (multiple_cmd[iter])
	{
		if (!(cmd_prm = ft_cmd_split(multiple_cmd[iter])))
				exit(2);
		if (ft_search_redirect_symbol(cmd_prm) == -1 && ((res = ft_builtin(cmd_prm, env)) == EXIT_SUCCESS))
		{
			return (EXIT_SUCCESS);
		}
		if (res == -1)
			return (-1);
		if ((pid = fork()) == 0)
		{
			if (ft_pipe_check(multiple_cmd[iter]) == EXIT_SUCCESS || ft_redirect_check(multiple_cmd[iter]) != -1)
			{
				res = fork_pipes(multiple_cmd[iter], *env);
			}
			else
			{
				res = ft_exe(multiple_cmd[iter], env);
			}
			exit(0);
		}
		wait(&exit_stat);
		if (WIFEXITED(exit_stat))
		{
			if (WEXITSTATUS(exit_stat) != 0)
				res = -1;
		}
		iter++;
	}
	return (res);
}
