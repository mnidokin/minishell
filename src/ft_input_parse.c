/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 22:27:19 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/20 22:27:35 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_input_parse(char *input_str) //* блок обработки на ";"
{
	char **res;

	res = NULL;
	res = ft_strsplit(input_str, ';');
	return (res);
}

int		ft_multiple_input(char **multiple_cmd, char ***env)
{
	int iter;
	int	res;

	iter = 0;
	res = 0;
	while (multiple_cmd[iter])
	{
		res = ft_exe(multiple_cmd[iter], env);
		if (res == -1)
			return (-1);
		iter++;
	}
	return (res);
}
