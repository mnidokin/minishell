/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arrow_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:31:40 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/29 02:24:53 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

t_uc		is_arrow_key(char *c)
{
	if (ft_strequ(c, SLCT_UP_ARROW))
		return (SLCT_PREV);
	if (ft_strequ(c, SLCT_DOWN_ARROW))
		return (SLCT_NEXT);
	if (ft_strequ(c, SLCT_LEFT_ARROW))
		return (SLCT_LEFT);
	if (ft_strequ(c, SLCT_OPT_LEFT_ARROW))
		return (SLCT_WORD_LEFT);
	if (ft_strequ(c, SLCT_SHIFT_LEFT_ARROW) ||
		ft_strequ(c, SLCT_HOME))
		return (SLCT_LINE_START);
	if (ft_strequ(c, SLCT_RIGHT_ARROW))
		return (SLCT_RIGHT);
	if (ft_strequ(c, SLCT_OPT_RIGHT_ARROW))
		return (SLCT_WORD_RIGHT);
	if (ft_strequ(c, SLCT_SHIFT_RIGHT_ARROW) || 
		ft_strequ(c, SLCT_END))
		return (SLCT_LINE_END);
	return (0);
}
