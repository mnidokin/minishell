#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define PATH 4069
typedef struct          s_envir
{
    char                *name;
    char                *value;
    struct  s_envir     *next;
}                       t_envir;

void	ft_prompt(void);
void	ft_free(t_envir **envir);
char	*ft_pwd(char *pwd);
t_envir	*ft_envir_lst(char **str);
t_envir *ft_envir_init(char *str);
void    ft_envir_lstaddback(t_envir **envir, t_envir *new);
void	ft_envir_shllchange(t_envir *envir);
void	ft_cmd_read(char **cmd);
void	ft_str_addchr(char **str, char c, int len);

#endif
