/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_arrow_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 02:19:19 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/26 02:19:40 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

t_uc		fire_arrow_key(char *key, char **line)
{
	t_uc	dir;

	if (!(dir = is_arrow_key(key)))
		return (FAIL);
	ft_arrow_key_action(dir, line);
	return (SUCCESS);
}
