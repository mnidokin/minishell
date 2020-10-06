#include "minishell.h"

void	ft_envir_arr(char **str, char **res)
{
	int	i;
	int	len;
	
	i = 0;
	len = 0;
	while (str[len])
		len++;
	if (!(res = ft_memalloc(len + 1)))
		exit(2);
	while (str[i])
	{
		res[i] = ft_strdup(str[i]);
		i++;
	}
	res[i] = NULL;
}