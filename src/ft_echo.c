#include "minishell.h"

int ft_builtin_echo(char **cmd)
{
	int newline_f;
	int	iter;

	newline_f = 0;
	iter = 1;
	if (!cmd[1])
	{
		ft_putendl("");
		return (0);
	}
	if (ft_strequ(cmd[1], "-n"))
	{
		newline_f = 1;
		iter++;
	}
	while (cmd[iter])
	{
		ft_echo(iter, cmd);
		ft_putendl("");
		iter++;
	}
	return (0);
}

int ft_echo(int iter, char **cmd)
{
	int len;

	len = ft_strlen(cmd[iter]);
	if ((cmd[iter][0] == '"' || cmd[iter][0] == '\'') &&
		(cmd[iter][len - 1] == '"' || cmd[iter][len - 1] == '\''))
		{
			ft_putnstr(cmd[iter] + 1, len - 2);
		}
	else
		ft_putstr(cmd[iter]);
	return (0);
}
static int ft_putchar_test(char c)
{
	write(1, &c, 1);
	return (0);
}

int	ft_putnstr(char *str, long int n)
{
	if (str == NULL || n == 0)
		return (0);
	//if (*str == '\0' | n == 0)
		//return (0);
	else
		return (ft_putchar_test(*str) + ft_putnstr(str + 1, n - 1));
}

