/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_deinit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 01:16:37 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/24 05:02:22 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

t_uc	ft_term_deinit(t_ttyfd *fd, t_screen *scrn)
{
	if (tcsetattr(fd->out, TCSAFLUSH, &(scrn->tty_old)))
		return (ft_perror(8, "Term deinit"));
	if (scrn->ws)
		free(scrn->ws);
	scrn->ws = NULL;
	if (fd->in != 0 && fd->in > 0)
	{
		close(fd->in);
		fd->in = STDIN_FILENO;
	}
	if (fd->out != 1 && fd->out > 0)
	{
		close(fd->out);
		fd->out = STDOUT_FILENO;
	}
	if (fd->err != 2 && fd->err > 0)
	{
		close(fd->out);
		fd->out = STDOUT_FILENO;
	}
	return (0);
}
