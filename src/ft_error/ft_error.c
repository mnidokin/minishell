/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 17:21:13 by mozzart           #+#    #+#             */
/*   Updated: 2020/10/13 15:04:23 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

static char		*get_errstr_1(t_uc errno_)
{
	char *errs[20];

	errs[0] = "Fail to open tty file descriptor";
	errs[1] = "Fail to get term name from environment";
	errs[2] = "Fail to get find termcap databaase";
	errs[3] = "Fail to find terminal in termcap database";
	errs[4] = "Not a tty";
	errs[5] = "Faile to deinit terminal (tcgetattr)";
	errs[6] = "Faile to deinit terminal (tcsetattr)";
	errs[7] = "Fail to allocate memmory";
	errs[8] = "Fail to get screen size";
	errs[9] = "Fail to set default settings for terminal";
	return (errs[errno_]);
}

void			ft_print_usage(char f, int exit_code)
{
	char	c;

	c = ft_isprint(f) ? f : 0;
	ft_dprintf(2, FT_PUSAGE, FT_PROG_NAME, c, FT_PUSAGE_ARGS);
	exit(exit_code);
}

t_uc			ft_perror(t_uc en, char *errstr)
{
	int	fd;

	fd = STDERR_FILENO;
	if (errstr)
		ft_dprintf(fd, "%s: %s\n", errstr, get_errstr_1(en - 1));
	else
		ft_dprintf(fd, "%s: %s\n", FT_PROG_NAME, get_errstr_1(en - 1));
	return (en);
}

void			ft_perr(char *file, char *errstr)
{
	ft_dprintf(2, FT_ERRSTR, FT_PROG_NAME, file, errstr);
}
