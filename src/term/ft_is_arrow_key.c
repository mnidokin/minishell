/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arrow_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:31:40 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/14 17:32:29 by tvanessa         ###   ########.fr       */
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
	if (ft_strequ(c, SLCT_RIGHT_ARROW))
		return (SLCT_RIGHT);
	return (0);
}
