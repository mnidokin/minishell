/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:55:37 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/27 14:47:57 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef LIBFT_H
#  include "libft.h"
# endif
# include "colors.h"
# ifndef FT_TYPES_H
#  include "ft_types.h"
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
# ifndef FT_TERM_H
#  include "ft_term.h"
# endif

# define REDIRECT_STD_OUTPUT 0
# define REDIRECT_STD_INPUT 1

int	g_pid;

/*
** ft_builtin.c
*/

int						ft_builtin(char **cmd, char ***env);
int						ft_builtin_env(char **env);

/*
** ft_cd_aux.c
*/

int						ft_cd_tilda(char ***env, char **cmd);
int						ft_cd_home(char ***env);

/*
** ft_cd.c
*/

int						ft_builtin_cd(char **cmd, char ***env);
int						ft_ch_dr(char *pth, char ***env);
void					ft_cd_error(char *pth);
int						ft_set_pwd(char ***env, char *env_name, char *pth);
char					*ft_cd_homereplace(char *cmd, char *home_path);

/*
** ft_cmd_split.c
*/

int						ft_space(char c);
char					**ft_word_eject(char *str);
char					**ft_cmd_split(char *str);
int						ft_word_count(char *str);
int						ft_word_len(char *str);

/*
** ft_cmd.c
*/

void					ft_cmd_read(char **cmd);
void					ft_str_addchr(char **str, char c, int len, t_us pos);

/*
** ft_echo.c
*/

int						ft_builtin_echo(char **cmd, char **env);
int						ft_echo(int iter, char **cmd, char **env);
char					*ft_echo_var(char *str, char **env);
int						ft_quote(int quote_flag, int iter, int len, char **cmd);
int						ft_quote_chek(char *str, int len);

/*
** ft_envir.c
*/

int						ft_env_init(char **src, char ***env);
int						ft_envir_strcount(char **str);

/*
** ft_exe_aux.c
*/

char					*ft_exe_chek_path(char **paths, char *cmd_prm);
char					*ft_exe_path_try(char *path, char *cmd_prm);
char					*ft_exe_pathjoin(char *path, char *cmd_prm);

/*
** ft_exe.c
*/

int						ft_exe(char *str, char ***env);
int						ft_exe_cmd(char **cmd_prm, char ***env);
int						ft_exe_notbuiltin(char ***env, char **cmd_prm, int res);
int						ft_exe_cve(char *cmd, char **cm_pr, char **env);

/*
** ft_free.c
*/

int						ft_free_mattr(char **mattr);

/*
** ft_input_parse.c
*/

char					**ft_input_parse(char *input_str);
int						ft_multiple_input(char **multiple_cmd, char ***env);

/*
** ft_path_parse.c
*/

char					**ft_path_parse(char **env);
int						ft_fullpath_check(char *cmd, char *full_path);
int						ft_get_env(char **env, char *str, char **res);
char					*ft_env_strdup(char *tmp);

/*
** ft_promt.c
*/

void					ft_promt(char **env);

/*
** ft_putnstr.c
*/

int						ft_putchar_recur(char c);
int						ft_putnstr(char *str, int n);

/*
** ft_pwd.c
*/

char					*ft_pwd(char *pwd);
int						ft_builtin_pwd(void);

/*
** ft_setenv.c
*/

int						ft_builtin_setenv(char **cmd, char ***env);
int						ft_setenv(char **cmd, char ***env);
char					**ft_setenv_value(char **cmd, int index, char **env);
char					**ft_setenv_nonvalue(char **cmd, int index, char **env);
char					**ft_setenv_expand(char **env);

/*
** ft_unsetenv.c
*/

int						ft_builtin_unsetenv(char **cmd, char ***env);
char					**ft_env_resize(int size, char ***env);
int						ft_remove_var(int index, char ***env);

/*
** ft_pipe.c
*/

int spawn_proc (int in, int out, char *cmd, char **env);
int fork_pipes (char *cmd, char **env);
int	ft_pipe_arg_num(char **pipe_ar);
/*
int	ft_pipe(char *cmd_line, char ***env);
int	ft_pipe_subproc_gen(char **pipe_ar, char ***env);
int	ft_pipe_exe(char *cmd, char ***env, int fd_in, int fd_out);
*/

/*
** ft_pipe_check.c
*/

int	ft_pipe_check(char *cmd_line);

/*
int	ft_process_pipes(char *line, char **envp);
void	ft_execute_child_proc(int in[], int out, char **cmd, char **envp);
int		fork_pipes(char **cmd, char **envp);
int		ft_contains(char *str, char c);
int		ft_array_len(char **arr);
*/

int	ft_redirect(char **cmd_prm, char ***env, int in_fd);
int	ft_search_char(char *str, char symbol);
int	ft_search_redirect(char **cmd);
int	ft_search_redirect_symbol(char **cmd);
void	ft_redirect_openfile(char *name, int redirection);
int	ft_redirect_isinput(char **cmd);
int	ft_redirect_check(char *cmd_line);

#endif
