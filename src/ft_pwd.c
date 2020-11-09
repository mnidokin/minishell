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

int ft_builtin_pwd(char **env)
{
	char *pth;

	ft_get_env(env, "PWD", &pth);
	ft_putendl(pth);
	return (0);
}
