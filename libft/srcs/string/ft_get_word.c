/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:57:35 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/26 04:44:55 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char		*ft_get_word(char const *start, t_uc dirrectoin, char *curr_ptr)
{
	t_uc	loop_exit_flag;
	char	*whitespaces;

	loop_exit_flag = 1;
	whitespaces = " \t\n\r";
	if (!start || !curr_ptr)
		return (NULL);
	if ((start == curr_ptr && dirrectoin & STR_SEARCH_LEFT) ||
		(!*curr_ptr && dirrectoin & STR_SEARCH_RIGHT))
		return (NULL);
	if (dirrectoin & STR_SEARCH_RIGHT)
	{
		while (*curr_ptr && !ft_strchr(whitespaces, *curr_ptr))
			++curr_ptr;
		while (*curr_ptr && ft_strchr(whitespaces, *curr_ptr))
			++curr_ptr;
	}
	if (dirrectoin & STR_SEARCH_LEFT)
	{
		while (curr_ptr != start && ft_strchr(whitespaces, *(curr_ptr - 1)))
			--curr_ptr;
		while (curr_ptr != start && !ft_strchr(whitespaces, *(curr_ptr - 1)))
			--curr_ptr;
	}
	return (curr_ptr);
}
