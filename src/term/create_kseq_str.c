/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_kseq_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 19:24:25 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/25 19:41:29 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static char	*create_format(char format[])
{
	int		i;
	char	*pattern;
	char	*delimiter;

	i = 0;
	pattern = "%s";
	delimiter = "|";
	ft_bzero(format, SLCT_KSEQ_COUNT * 3);
	while (i < SLCT_KSEQ_COUNT)
	{
		if (i)
			ft_strcat(format, delimiter);
		ft_strcat(format, pattern);
		++i;
	}
	return (format);
}

char	*create_kseq_str(void)
{
	char *seqs;
	char	format[SLCT_KSEQ_COUNT * 3];


	create_format(format);
	seqs = ft_vprintf(format,
						SLCT_CTRL_GROUND,
						SLCT_ESC_C,
						SLCT_ESC_UC,
						SLCT_ESC_X,
						SLCT_ESC_UX,
						SLCT_ESC_UD,
						SLCT_ESC_D,
						SLCT_ESC_DF,
						SLCT_ESC_V,
						SLCT_DEL);
	ft_bzero(format, SLCT_KSEQ_COUNT * 3);
	return (seqs);
}