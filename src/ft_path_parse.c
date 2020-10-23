#include "minishell.h"

char	**ft_path_parse(void)
{
	char *str;
	char **tmp;

	str = ft_path_get();
	tmp = ft_strsplit(str, ':');
	return (tmp);
}

char	*ft_path_get(void)
{
	int i;
	char	*res;
	char	**tmp;

	i = 0;
	while (g_env[i])
	{
		if (ft_strncmp(g_env[i], "PATH=", 5) == 0)
		{
			if (!(tmp = ft_strsplit(g_env[i], '=')))
				exit(2);
			return (res = ft_strdup(tmp[1]));
		}
		i++;
	}
	return (NULL);
}
