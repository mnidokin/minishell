/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 23:12:40 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/09 21:56:20 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

void	*env_destroy(t_env *env)
{
	if (!env)
		return (NULL);
	env->add = NULL;
	env->all = NULL;
	env->del = NULL;
	env->get = NULL;
	env->set = NULL;
	env->destroy = NULL;
	env->len = NULL;
	ft_strdel(&env->name);
	ft_strdel(&env->value);
	ft_strdel(&env->origin);
	env->origin = NULL;
	env->next = env->next ? env->next->destroy(env->next) : NULL;
	free(env);
	env = NULL;
	return (NULL);
}

t_env	*env_new(char **ev)
{
	t_env	*env;

	if (!ev || !*ev || !**ev)
		return (NULL);
	if (!(env = env_new_var(*ev)))
		return (NULL);
	env->next = env_new(ev + 1);
	return (env);
}
