/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 22:51:09 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/21 01:29:42 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memclr(void *mem, size_t size)
{
	char	*s;

	s = (char*)mem;
	if (s)
		while (size--)
			s[size] = 0;
	ft_memdel(&mem);
}
