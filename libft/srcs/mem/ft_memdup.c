/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 18:57:53 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/19 19:35:06 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *mem, size_t size)
{
	char *res;

	res = NULL;
	if (!size || !(res = (char*)malloc(size)))
		return (NULL);
	while (size--)
		res[size] = ((char*)(mem))[size];
	return ((void*)res);
}