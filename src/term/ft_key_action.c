/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:06:14 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/26 02:26:07 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

t_uc		ft_key_action(char *key, char **line)
{
	if (fire_arrow_key(key, line) == SUCCESS)
		return (1);
	if ((fire_new_line_key(key)) == SUCCESS)
		return (1);
	if (fire_del_keys(key, line) == SUCCESS)
		return (1);
	if (fire_copy_keys(key, line) == SUCCESS)
		return (1);
	if (fire_cut_keys(key, line) == SUCCESS)
		return (1);
	if (fire_paste_keys(key, line) == SUCCESS)
		return (1);
	if ((fire_abort_code_key(key, line)) == SUCCESS)
		return (1);
	if ((fire_eof_key(key, line)) == SUCCESS)
		return (1);
	return (0);
}
