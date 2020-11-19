#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

void					ft_prompt(void);
char					*ft_pwd(char *pwd);
int						ft_builtin_pwd(void);
int						ft_free_mattr(char **mattr);
int						ft_env_init(char **src, char ***env);
int						ft_envir_strcount(char **str);
void					ft_cmd_read(char **cmd);
void					ft_str_addchr(char **str, char c, int len);
int						ft_space(char c);
char					**ft_cmd_split(char *str);
char					**ft_word_eject(char *str);
int						ft_word_count(char *str);
int						ft_word_len(char *str);
int						ft_builtin(char **cmd, char ***env);
int						ft_builtin_env(char **env);
int						ft_exe(char *str, char ***env);
int						ft_exe_cmd(char **cmd_prm, char ***env);
int						ft_exe_cve(char *cmd, char **cm_pr, char **env);
char					**ft_path_parse(char **env);
int						ft_get_env(char **env, char *str, char **res);
char					*ft_exe_chek_path(char **paths, char *cmd_prm);
int						ft_fullpath_check(char *cmd, char *full_path);
int						ft_builtin_setenv(char **cmd, char ***env);
int						ft_setenv(char **cmd, char ***env);
char					**ft_setenv_value(char **cmd, int index, char **env);
char					**ft_setenv_nonvalue(char **cmd, int index, char **env);
char					**ft_setenv_expand(char **env);
int						ft_builtin_unsetenv(char **cmd, char ***env);
char					**ft_env_realloc(int size, char ***env);
int						ft_remove_var(int index, char ***env);
int						ft_builtin_cd(char **cmd, char ***env);
int						ft_ch_dr(char *pth, char ***env);
int						ft_set_pwd(char ***env, char *env_name, char *pth);
char					*ft_cd_homereplace(char *cmd, char *home_path);
int						ft_builtin_echo(char **cmd, char **env);
int						ft_echo(int iter, char **cmd, char **env);
int						ft_putnstr(char *str, long int n);
char					*ft_echo_var(char *str, char **env);
int						ft_quote_chek(char *str, int len);

#endif
