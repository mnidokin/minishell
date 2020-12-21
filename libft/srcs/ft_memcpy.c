/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:31:23 by tvanessa          #+#    #+#             */
/*   Updated: 2020/09/22 23:25:55 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*r;
	char		*s;
	size_t		i;

	r = (char*)dst;
	s = (char*)src;
	i = -1;
	if (r && s && n)
		while (++i < n)
			r[i] = s[i];
	return (dst);
}
