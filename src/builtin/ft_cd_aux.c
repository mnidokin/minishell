/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:29:33 by mnidokin          #+#    #+#             */
/*   Updated: 2020/11/19 23:29:58 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_cd_tilda(char ***env, char **cmd)
{
	char	*full_path;
	char	*home_path;
	int		res;

	ft_get_env(*env, "HOME", &home_path);
	full_path = ft_cd_homereplace(cmd[0], home_path);
	res = ft_ch_dr(full_path, env);
	free(full_path);
	free(home_path);
	return (res);
}

int		ft_cd_home(char ***env)
{
	char	*home_path;
	int		res;

	ft_get_env(*env, "OLDPWD", &home_path);
	res = ft_ch_dr(home_path, env);
	free(home_path);
	return (res);
}
