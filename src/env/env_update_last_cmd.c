/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_update_last_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 22:27:36 by mozzart           #+#    #+#             */
/*   Updated: 2020/10/04 17:19:24 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

t_uc	env_update_last_cmd(char *cmd, t_env **env)
{
	char	tmp[PATH_MAX];

	tmp[0] = '_';
	tmp[1] = '=';
	if (env && *env)
	{
		if ((*env)->set(*env, "_", cmd))
			if ((*env)->add(*env, "_", cmd))
				return (1);
	}
	else if (!*env)
	{
		ft_strcat(tmp, cmd);
		if (!(*env = env_new_var(tmp)))
			return (1);
		ft_bzero(tmp, PATH_MAX);
	}
	return (0);
}
