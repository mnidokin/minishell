#include "minishell.h"

char *ft_pwd(char *buf)
{
    char	*res;
    int		len;

    res = getcwd(buf, 1024);
    len = ft_strlen(res);
    res = ft_strdup(getcwd(buf, len+1));
    return(res);
}

int ft_builtin_pwd()
{
	char *pth;
	char buf[1024];

	pth = ft_pwd(buf);
	ft_putendl(pth);
	free(pth);
	return (0);
}
