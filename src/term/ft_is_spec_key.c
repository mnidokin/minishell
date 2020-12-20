/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_spec_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:04:13 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/20 20:40:53 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

t_uc	ft_is_spec_key(char *input)
{
	if (ft_strequ(input, SLCT_ESC))
		return (1);
	if (is_arrow_key(input))
		return (1);
	if (ft_strequ(input, SLCT_DEL))
		return (1);
	if (ft_strequ(input, SLCT_BSP))
		return (1);
	if (ft_strequ_any(input, "\xa|\x4|\x3"))
		return (1);
	if (ft_strequ(input, "\r"))
		return (1);
	if (ft_strequ(input, SLCT_HTAB))
		return (1);
	if (ft_strequ(input, SLCT_VTAB))
		return (1);
	return (0);
}