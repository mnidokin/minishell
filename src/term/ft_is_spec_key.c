/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_spec_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:04:13 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/26 05:30:45 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

t_uc	ft_is_spec_key(char *input)
{
	t_uc	input_len;

	input_len = ft_strlen(input);
	if (input_len == 1 && (input[0] < '\x20' || input[0] > '~'))
			return (1);
	if (input_len > 1 && input[0] == '\e')
	{
		if (ft_strchr("bf[", input[1]) && is_arrow_key(input))
			return (1);
		if (ft_strcmp_any(input, SLCT_KSEQ_STR))
			return (1);
	}
	return (0);
}
