/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:51:18 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/25 18:50:30 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_vprintf(const char *restrict format, ...)
{
	t_arg		*arg;
	va_list		ap;
	char		*i;

	i = 0;
	arg = ft_newarg('q');
	ft_bzero(arg->buff, SIZE);
	if (format)
	{
		va_start(ap, format);
		i = parsing_str_format_v(arg, ap, format);
		va_end(ap);
	}
	i = ft_strdup(i);
	free(arg);
	return (i);
}
