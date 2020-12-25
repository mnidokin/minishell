/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_str_format_v.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:43:25 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/25 17:53:41 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*parsing_str_format_v(t_arg *a, va_list ap, const char *f)
{
	t_f_arg		*fl_st;

	fl_st = ft_newarg_flags();
	while (*f)
	{
		if (*f == 37)
		{
			use_mod(st_flags((mod_in(f, a)), fl_st, ap), a, ap);
			if (a->index_f < 0)
				break ;
			f = f + a->index_f;
			a->index_f = 0;
		}
		else
		{
			a = write_char_no_mod(a, *f);
			f++;
		}
	}
	if (*f == 0 && (!a->buff[0]))
		return (NULL);
	a->value = a->value + a->index_buff;
	free(fl_st);
	return (a->buff);
}
