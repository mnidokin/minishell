/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:57:20 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/21 17:19:48 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_promt_get_pwd(char **env)
{
	char	*pwd;
	char	**pwd_split;
	int		index;

	index = 0;
	ft_get_env(env, "PWD", &pwd);
	pwd_split = ft_strsplit(pwd, '/');
	while (pwd_split[index + 1])
	{
		index++;
	}
	
	return (pwd_split[index]);
}

void	ft_prompt(char **env)
{
	ft_putstr(COLOR_CYAN);
	ft_putstr(" ");
	ft_putstr(ft_promt_get_pwd(env));
	ft_putstr(" ");
	ft_putstr(COLOR_GREEN);
	ft_putstr("> ");
	ft_putstr(COLOR_FLUSH);
}
