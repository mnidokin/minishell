/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:57:55 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/21 01:03:44 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static t_uc	ft_getscreen(t_screen *screen, t_ttyfd *fd)
{
	if (!screen->ws)
		if (!(screen->ws = (struct winsize*)malloc(sizeof(struct winsize))))
			return (ft_perror(8, "Get screen"));
	if ((ioctl(fd->out, TIOCGWINSZ, screen->ws)) < 0)
		return (ft_perror(9, "Get screen"));
	ft_cursor_pos(fd, screen->home);
	ft_cursor_pos(fd, screen->cursor_pos);
	return (0);
}

static t_uc	get_io(t_ttyfd *fd)
{
	fd->in = STDIN_FILENO;
	fd->out = STDOUT_FILENO;
	fd->err = STDERR_FILENO;
	if (!(isatty(fd->out)))
	{
		fd->in = open("/dev/tty", (O_RDONLY));
		fd->out = open("/dev/tty", (O_WRONLY | O_NDELAY));
		if (fd->in < 0 || fd->out < 0)
		{
			fd->in >= 0 ? close(fd->in) : 0;
			fd->out > 0 ? close(fd->out) : 0;
			return (1);
		}
	}
	return (0);
}

static void	ft_set_term_vals(t_tios *ntty, t_tios *otty)
{
	(void)otty;
	ntty->c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
	ntty->c_oflag &= ~(OPOST);
	ntty->c_iflag &= ~(IXON | IXOFF | ICRNL);
	ntty->c_cc[VMIN] = 1;
	ntty->c_cc[VTIME] = 0;
}

static t_uc	ft_prepare_tty(t_screen *scrn, t_ttyfd *fd, t_bl tty)
{
	if (!tty)
	{
		if (!(isatty(fd->out)))
			return ((ft_perror(5, "Term init")));
		if (ioctl(fd->out, TIOCGETA, &(scrn->tty_old)) < 0)
			return (ft_perror(6, "Term init"));
		ft_set_term_vals(&(scrn->tty_new), &(scrn->tty_old));
		if (ioctl(fd->out, TIOCSETA, &(scrn->tty_new)) < 0)
			return (ft_perror(7, "Term init"));
		return (0);
	}
	if (tcgetattr(g_term.fd.out, &(scrn->tty_old)))
		return ((ft_perror(6, "Term init")));
	ft_set_term_vals(&(scrn->tty_new), &(scrn->tty_old));
	if (tcsetattr(g_term.fd.in, TCSANOW, &(scrn->tty_new)))
		return ((ft_perror(7, "Term init")));
	return (0);
}

t_uc		ft_term_init(t_ttyfd *fd, t_screen *screen)
{
	char	*termtype;
	t_uc	ret;
	char	*tty;
	char	*buf;
	char	*fn;

	buf = NULL;
	fn = "Term init";
	if (get_io(fd))
		return (ft_perror(1, fn));
	if (!(termtype = getenv("TERM")))
		return (ft_perror(2, fn));
	if ((ret = tgetent(buf, termtype)) == 0 || ret == (t_uc)-1)
		return (ret ? (ft_perror(3, fn)) : (ft_perror(4, fn)));
	tty = ttyname(STDOUT_FILENO);
	if ((ret = ft_prepare_tty(screen, fd, tty ? ft_true : ft_false)))
		return (ret);
	if ((ret = ft_getscreen(screen, fd)))
		return (ret);
	return (0);
}
