/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_promt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:57:20 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/25 18:15:14 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_promt(char **env)
{
	(void)env;
	ft_putstr(COLOR_YELLOW);
	ft_putstr(ft_get_promt());
	ft_putstr(COLOR_FLUSH);
}
