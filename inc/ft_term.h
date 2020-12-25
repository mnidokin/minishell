/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 00:53:43 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/25 20:01:00 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_H
# define FT_TERM_H
# include <termcap.h>
# include <term.h>
# ifndef FT_TYPES_H
#  include "ft_types.h"
# endif
# ifndef LIBFT_H
#  include "libft.h"
# endif
# ifndef FT_STRING_H
#  include "ft_string.h"
# endif
# ifndef FT_ERROR_H
#  include "ft_error.h"
# endif
# ifndef FT_ENV_H
#  include "ft_env.h"
# endif
# ifndef FT_SH_HISTORY_H
#  include "ft_sh_history.h"
# endif

/*
** Arrow keys
*/
# define SLCT_UP_ARROW				"\e[A"			// History up
# define SLCT_DOWN_ARROW			"\e[B"			// History down
# define SLCT_RIGHT_ARROW			"\e[C"			// Cursor move right
# define SLCT_OPT_RIGHT_ARROW		"\ef"			// Cursor move right by word
# define SLCT_CTRL_CMD_RIGHT_ARROW	"\e[1;5C"
# define SLCT_SHIFT_RIGHT_ARROW		"\e[1;2C"		// Move cursor to end of line
# define SLCT_LEFT_ARROW			"\e[D"			// Cursor move left
# define SLCT_OPT_LEFT_ARROW		"\eb"			// Cursor move left by word
# define SLCT_CTRL_CMD_LEFT_ARROW	"\e[1;5D"
# define SLCT_SHIFT_LEFT_ARROW		"\e[1;2D"		// Cursor move ot start of line

/*
** Copy special keys
*/
# define SLCT_CTRL_Y				"\x19" 			// yank line
# define SLCT_CTRL_GROUND			"\e\x1f" 		// copy-prev-word
# define SLCT_ESC_C					"\ec" 			// backword-copy-word
# define SLCT_ESC_UC				"\eC" 			// forword-copy-word

/*
** Cut special keys
*/
# define SLCT_ESC_X					"\ex" 			// backword-cut-word
# define SLCT_ESC_UX				"\eX" 			// forkword-cut-word
# define SLCT_ESC_UXL				"\eXl" 			// cut-line


/*
** Delete special keys
*/
# define SLCT_CTRL_U				"\x15" 			// kill-whole-line
# define SLCT_CTRL_K				"\v" 			// kill-line
# define SLCT_CTRL_W				"\x17" 			// backward-kill-word
# define SLCT_ESC_UD				"\eD"			// kill-line
# define SLCT_ESC_D					"\ed"			// backword-kill-word
# define SLCT_ESC_DF				"\efd"			// forword-kill-word

/*
** Other special keys
*/
# define SLCT_ENTER					"\n"			// New line
# define SLCT_ESC					"\e"			// Special sequence introduser/exiter
# define SLCT_HTAB					"\t"			// Autocomplition
# define SLCT_ESC_V					"\ev"			// Paste from clipboard
# define SLCT_BSP					"\x7f"			// Backword-delete-char
# define SLCT_DEL					"\e[3~"			// Forword-delete-char

# define SLCT_KSEQ_COUNT			10
# define SLCT_KSEQ_STR				create_kseq_str()


# define SH_EOCMD					1
# define SH_SPEC_KEY				2
# define SH_WAIT_SEQ				3

/*
** Control Siquence Itroducer or '[' char
*/
# define SLCT_CSI '['
/*
** Get current cursor position in "\\e[r;cR" format
*/
# define SLCT_GCCP "\e[6n"

# define SLCT_ORIGINE_VALUE	1
# define CLST_PRNT_ALL		0
# define CLST_PRNT_CURR		1
# define CLST_PRNT_ACT		2
# define CLST_PRNT_SLCT		3
# define CLST_PRNT_SLCT_OL	4
# define SLCT_PREV			0b000001
# define SLCT_NEXT			0b000010
# define SLCT_LEFT			0b000100
# define SLCT_RIGHT			0b001000
# define SLCT_WORD			0b010000
# define SLCT_WORD_LEFT		SLCT_WORD | SLCT_LEFT 
# define SLCT_WORD_RIGHT	SLCT_WORD | SLCT_RIGHT
# define SLCT_LINE			0b100000
# define SLCT_LINE_START	SLCT_LINE | SLCT_LEFT
# define SLCT_LINE_END		SLCT_LINE | SLCT_RIGHT
// # define STDIN open("/dev/tty", (O_RDONLY))
// # define STDOUT open("/dev/tty", (O_WRONLY | O_NDELAY))
# ifndef t_tios
#  ifdef _SYS_TERMIOS_H_
typedef struct termios t_tios;
#  endif
# endif

typedef struct		s_ttyfd
{
	int				in;
	int				out;
	int				err;
}					t_ttyfd;

typedef	struct		s_screen
{
	struct winsize	*ws;
	t_us			home[2];
	t_us			cursor_pos[2];
	t_tios			tty_old;
	t_tios			tty_new;
}					t_screen;

typedef struct		s_citem
{
	char			*data;
	t_bl			active;
	t_bl			selected;
	t_us			coords[2];
	struct s_citem	*prev;
	struct s_citem	*next;

	void			(*print)(struct s_citem*, t_ttyfd*);
	void			(*select)(struct s_citem*);
	void			(*activate)(struct s_citem*, t_ttyfd*);
	void			*(*destroy)(struct s_citem**);
}					t_citem;

typedef struct		s_clist
{
	struct s_citem	*start;
	struct s_citem	*current;
	struct s_citem	*end;
	size_t			len;
	t_bl			search_mode;

	void			(*print)(struct s_clist*, t_ttyfd*, t_screen*);
	void			(*erase)(struct s_citem*);
	void			*(*destroy)(struct s_clist**);
}					t_clist;

typedef	struct	s_term
{
	t_ttyfd		fd;
	t_screen	screen;
	size_t		cmd_len;
}				t_term;

t_term	g_term;
/*
** Data may not be NULL, but *data - can be null
** in this case creates new list with start prop pointed to
** item with NULL data.
** If Data is NULL - returns NULL, otherwise created new list
** with start property points to first item
** Previoce and next props of citems initialize in this function
** If there are not previoce (i.e. for first item) or next (i.e. for last)
** item, then they are stores values to last and first items respectevly.
** By default active flag sets to 1 (or TRUE) to first item and selected sets
** to 0 (FALSE) for all items
** Current property stores pointer to active item
** If no data argument passed, or if fail to malloc memory for the list returns NULL
** If Fails to malloc memory for item, than destroy all list with item and
** returns NULL
*/
t_clist	*new_clist(char **data_set, int set_size);
/*
** Create new citem.
** Data prop points to data argument
** If SLCTT_ORIGINE_VALUE defined and its value equal to 1 (?or TRUE)
** than in data props stores pointer to origin memmory, otherwise data argument
** duplicated to data prop.
** If data argument is NULL, then NULL returns
** Previoce and next props initialise with NULL values
** Active and selected props sets to 0 (FALSE) values
** If fail to malloc memory for item or for data (if needed), then returns NULLs
*/
t_citem	*new_citem(char *data);
/*
** Send command to terminal
** Cmd is command describe in Termcap documentation
** return 0 on success, 1 if faile tgetstr call and 2 on tputs fail call.
**
*/
t_uc	ft_term_send_command(char *cmd);
/*
**
*/
void	ft_goto(t_clist *lst, t_uc dirr, t_ttyfd *fd, t_screen *scrn);
/*
**
*/
void	ft_select(t_clist *lst, t_ttyfd *fd, t_screen *screen);
/*
**
*/
size_t	ft_erase(t_clist *lst, t_ttyfd *fd, t_screen *screen);
/*
**
*/
void	ft_cursor_pos(t_ttyfd *fd, t_us *coords);
/*
** 
*/
void	ft_cursor_move_to(t_ttyfd *fd, t_us row, t_us col);
/*
** 
*/
int		ft_putc(int c);
/*
** 
*/
void	ft_set_sig(t_clist *lst, t_ttyfd *fd, t_screen *scrn);
/*
** 
*/
t_uc	ft_term_deinit(t_ttyfd *fd, t_screen *scrn);
/*
** 
*/
t_uc	ft_term_init(t_ttyfd *fd, t_screen *screen);
/*
** 
*/
int		ft_sig_init(int sig, t_clist *lst, t_ttyfd *fd, t_screen *scrn);
/*
** 
*/
t_uc	routin_(t_ttyfd *fd, t_clist *lst, t_screen *scrn);
/*
** 
*/
void	search_mode(t_ttyfd *fd, t_clist *lst, t_screen *screen);
/*
** 
*/
void	ft_eraese_char(t_ttyfd *fd, char *buf);
/*
** 
*/
t_uc	ft_is_exit_cond(t_ttyfd *fd, t_clist *lst, t_citem *it, char *c);
/*
** ?????
*/
void	ft_sns(char *heystack, t_uc k, t_clist *lst, t_ttyfd *fd);
/*
** 
*/
void	init_search_mode(t_ttyfd *fd, t_clist *lst, t_screen *scrn);
/*
** 
*/
void	deinit_search_mode(t_ttyfd *fd, t_screen *scrn, t_clist *lst);
/*
** 
*/
void			print_underscore(char *str, t_ttyfd *fd);
/*
** 
*/
void			print_active_item(char *str, t_ttyfd *fd, size_t l);
/*
** 
*/
void			print_underscore_inverse(char *str, t_ttyfd *fd);
/*
** 
*/
void			nprint_inverse(char *str, t_ttyfd *fd, size_t l);
/*
** 
*/
void			print_inverse(char *str, t_ttyfd *fd);
/*
** 
*/
t_bool	search_data(t_clist *lst, t_ttyfd *fd, char *ndl);
/*
** 
*/
void	reload(int sig);
/*
** 
*/
t_citem	*clst_fill(int size, char **data, t_clist *lst);
/*
** 
*/
t_uc	is_arrow_key(char *c);
/*
** 
*/
t_uc	ft_is_spec_key(char *input);
/*
** 
*/
t_uc	ft_key_action(char *key, char **buf);
/*
**
*/
void	ft_arrow_key_action(t_uc dirrection, char **line);
/*
**
*/
int				read_term(char **line);
/*
**
*/
char				 	*ft_get_promt(void);
void	ft_cursor_left(void);
void	ft_cursor_right(void);
void	ft_history_up(char **line);
void	ft_history_down(char **line);
void	ft_clear_line(char *line);
char	*create_kseq_str(void);

#endif