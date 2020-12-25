/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_spec_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:04:13 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/25 19:37:54 by mozzart          ###   ########.fr       */
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
		if (ft_strequ_any(input, SLCT_KSEQ_STR))
			return (1);
	}
	return (0);
}
