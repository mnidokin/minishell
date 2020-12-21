/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:00:38 by mnidokin          #+#    #+#             */
/*   Updated: 2020/11/20 15:37:17 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_putchar_recur(char c)
{
	write(1, &c, 1);
	return (0);
}

int		ft_putnstr(char *str, int n)
{
	if (str == NULL || n == 0)
		return (0);
	else
		return (ft_putchar_recur(*str) + ft_putnstr(str + 1, n - 1));
}
