/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_history.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:12:18 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/21 01:33:57 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_HISTORY_H
# define FT_SH_HISTORY_H
# ifndef LIBFT_H
#  include "libft.h"
# endif
# ifndef FT_TYPES_H
#  include "ft_types.h"
# endif
# ifndef FT_STRING_H
#  include "ft_string.h"
# endif
# ifndef FT_DLST_H
#  include "ft_dlst.h"
# endif

# define HIST_MAXLEN 10

typedef struct	s_sh_history
{
	t_us		fd;
	t_dlist		*current;
	t_us		len;

	t_uc		(*add)(char*);
	char		*(*get)(t_uc);
	t_uc		(*destroy)(void);
}				t_sh_history;

# ifndef t_history

typedef t_sh_history	t_history;
# endif

enum		e_hist_errs
{
	E_HIST_SUCCESS,
	E_HIST_MALLOC,
	E_HIST_FOERR,
	E_HIST_DATAFILL,
	E_HIST_NO
};

enum		e_hist_dirrections
{
	HIST_UP,
	HIST_DOWN
};

t_uc		ft_init_history(void);
/*
** Singletone for history structure
** To get initialized history just call with NULL parameter
** Worked after ft_init_history call!!!
*/
t_history	*ft_history(t_history **history);
t_uc		ft_history_save(void);
t_uc		ft_history_destroy(t_history **history, t_uc err);

#endif
