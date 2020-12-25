/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_new_line_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 02:20:20 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/26 02:27:00 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

t_uc	fire_new_line_key(char *key)
{
	if (!(ft_strequ(key, "\r")))
		return (FAIL);
	ft_term_send_command("cr");
	ft_term_send_command("do");
	return (SUCCESS);
}
