#include "minishell.h"

void	ft_cmd_read(char **cmd)
{
	int		len;
	char	c;

	len = 0;
	while (1)
	{
		if (!(read(0, &c, 1)))
			break ;
		if (c == '\n' && len == 0)
		{
			*cmd = NULL;
			break ;
		}
		if (c == '\n' && len > 0)
			break ;
		if (len > 0)
			ft_str_addchr(cmd, c, len);
		else
		{
			*cmd = ft_strnew(len + 1);
			*cmd[len] = c;
		}
		len++;
	}
}

void	ft_str_addchr(char **str, char c, int len)
{
	char *tmp;

	tmp = ft_strdup(*str);
	ft_strdel(&(*str));
	*str = ft_strnew(len + 1);
	ft_strncpy((*str), tmp, len);
	ft_strdel(&tmp);
	(*str)[len] = c;
}
