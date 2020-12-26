/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_cut_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 04:12:36 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/26 04:53:12 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

t_uc	fire_cut_keys(char *key, char **line)
{
	if (ft_strequ(key, SLCT_ESC_UXL))
	{
		fire_copy_keys(SLCT_CTRL_Y, line);
		fire_del_keys(SLCT_CTRL_U, line);
		return (SUCCESS);
	}
	if (ft_strequ(key, SLCT_ESC_X))
	{
		fire_copy_keys(SLCT_ESC_C, line);
		fire_del_keys(SLCT_CTRL_W, line);
		return (SUCCESS);
	}		
	if (ft_strequ(key, SLCT_ESC_UX))
	{
		fire_copy_keys(SLCT_ESC_UC, line);
		fire_del_keys(SLCT_ESC_DF, line);
		return (SUCCESS);
	}		
	return (FAIL);
}