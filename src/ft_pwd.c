#include "minishell.h"

char *ft_pwd(char *pwd)
{
    char	*res;
    int		len;

    res = getcwd(pwd, 4096);
    len = ft_strlen(res);
    free(res);
    res = getcwd(pwd, len+1);
    return(res);
}