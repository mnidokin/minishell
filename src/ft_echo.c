/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:56:53 by mnidokin          #+#    #+#             */
/*   Updated: 2020/11/19 22:56:53 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_builtin_echo(char **cmd, char **env)
{
	int newline_f;
	int	iter;

	newline_f = 0;
	iter = 1;
	if (!cmd[1])
	{
		ft_putendl("");
		return (0);
	}
	if (ft_strequ(cmd[1], "-n"))
	{
		newline_f = 1;
		iter++;
	}
	while (cmd[iter])
	{
		ft_echo(iter, cmd, env);
		iter++;
	}
	if (!newline_f)
		ft_putendl("");
	return (0);
}

int		ft_echo(int iter, char **cmd, char **env)
{
	int		len;
	int		quote_flag;
	char	*env_var;

	len = ft_strlen(cmd[iter]);
	quote_flag = ft_quote_chek(cmd[iter], len);
	if (quote_flag == 1)
		ft_putnstr(cmd[iter] + 1, len - 2);
	else if (quote_flag == 2)
		ft_putstr(cmd[iter] + 1);
	else if (quote_flag == 3)
		ft_putnstr(cmd[iter], len - 1);
	else
	{
		if (cmd[iter][0] == '$' && cmd[iter][1])
		{
			env_var = ft_echo_var((cmd[iter] + 1), env);
			if (env_var)
			{
				ft_putstr(env_var);
				free(env_var);
			}
		}
		else
			ft_putstr(cmd[iter]);
	}
	if (cmd[iter + 1])
		ft_putchar(' ');
	return (0);
}

int		ft_putchar_test(char c)
{
	write(1, &c, 1);
	return (0);
}

int		ft_putnstr(char *str, long int n)
{
	if (str == NULL || n == 0)
		return (0);
	else
		return (ft_putchar_test(*str) + ft_putnstr(str + 1, n - 1));
}

char	*ft_echo_var(char *str, char **env)
{
	char	*res;
	int		index;

	index = ft_get_env(env, str, &res);
	if (index == -1)
		return (NULL);
	return (res);
}

int		ft_quote_chek(char *str, int len)
{
	if ((str[0] == '"' || str[0] == '\'') &&
		(str[len - 1] == '"' || str[len - 1] == '\''))
		return (1);
	else if ((str[0] == '"' || str[0] == '\''))
		return (2);
	else if ((str[len - 1] == '"' || str[len - 1] == '\''))
		return (3);
	return (0);
}
