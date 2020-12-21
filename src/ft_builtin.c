/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:56:32 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/21 17:19:05 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_builtin(char **cmd, char ***env)
{
	if (ft_strequ(cmd[0], "exit"))
	{
		return (-1);
	}
	else if (ft_strequ(cmd[0], "setenv"))
		return (ft_builtin_setenv(cmd, env));
	else if (ft_strequ(cmd[0], "unsetenv"))
		return (ft_builtin_unsetenv(cmd, env));
	else if (ft_strequ(cmd[0], "env"))
		return (ft_builtin_env(*env));
	else if (ft_strequ(cmd[0], "cd"))
		return (ft_builtin_cd(cmd, env));
	else if (ft_strequ(cmd[0], "pwd"))
		return (ft_builtin_pwd());
	else if (ft_strequ(cmd[0], "echo"))
		return (ft_builtin_echo(cmd, *env));
	return (2);
}

int	ft_builtin_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
	return (0);
}
