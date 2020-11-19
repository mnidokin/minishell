/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:14:06 by mnidokin          #+#    #+#             */
/*   Updated: 2020/11/19 23:30:17 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_free_mattr(char **mattr)
{
	int index;

	index = 0;
	while (mattr[index])
	{
		free(mattr[index]);
		index++;
	}
	free(mattr);
	return (0);
}
