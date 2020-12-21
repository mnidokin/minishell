/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 16:20:31 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/14 18:05:04 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H
# ifndef LIBFT_H
#  include "libft.h"
# endif
# ifndef FT_TYPES_H
#  include "ft_types.h"
# endif
# include "ft_errs.h"

# define FT_PROG_NAME "21sh"
# define FT_PUSAGE "%s: Too few arguments %c\nusage: ft_select %s\n"
# define FT_PUSAGE_ARGS "choice1 [choice2 ...]"
# define FT_ERRSTR "%s: %s: %s\n"

# define FT_E_NOTICE 0x1;
# define FT_E_WARN 0x2;
# define FT_E_FATAL 0x3;

typedef struct		s_error
{
	t_uc			type;
}					t_error;

typedef struct		s_err
{
	t_error			*err;
}					t_err;

// void				ft_perr(int errno, char *func_name);
void				ft_perr(char *file, char *errstr);
void				ft_print_usage(char f, int exit_code);
t_uc				ft_perror(t_uc en, char *errstr);

#endif
