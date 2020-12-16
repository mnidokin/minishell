/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_key_action.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:49:04 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/14 17:59:35 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void	ft_cursor_left(void)
{
	ft_term_send_command("le");
}

void	ft_cursor_right(void)
{
	ft_term_send_command("nd");
}

void	ft_history_up(void)
{

}

void	ft_history_down(void)
{

}

void	ft_arrow_key_action(t_uc dirrection)
{
	if (dirrection == SLCT_PREV)
		ft_history_up();
	if (dirrection == SLCT_NEXT)
		ft_history_down();
	if (dirrection == SLCT_RIGHT)
		ft_cursor_right();
	if (dirrection == SLCT_LEFT)
		ft_cursor_left();
}