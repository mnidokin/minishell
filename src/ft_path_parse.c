#include "minishell.h"

char	**ft_path_parse(char **env)
{
	char *str;
	char **tmp;

	ft_get_env(env, "PATH", &str);
	tmp = ft_strsplit(str, ':');
	return (tmp);
}

int		ft_get_env(char **env, char *str, char **res)
{
	int i;
	char	**tmp;
	char	*key;

	i = 0;
	while (env[i])
	{
		key = ft_strjoin(str, "=");
		if (ft_strncmp(env[i], key, ft_strlen(key)) == 0)
		{
			if (!(tmp = ft_strsplit(env[i], '=')))
				exit(2);
			if (res)
				(*res) = ft_strdup(tmp[1]);
			return (i);
		}
		free(key);
		i++;
	}
	return (i);
}
