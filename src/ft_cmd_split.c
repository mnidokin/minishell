#include "minishell.h"

int		ft_space(char c)
{
	if (c == '\v' || c == '\t' || c == '\r' || c == ' ')
		return (0);
	return (1);
}

char	**ft_word_eject(char *str)
{
	char	**res;
	int		row;
	int		col;
	int		wc;

	wc = ft_word_count(str);
	row = 0;
	if (!str || !(res = (char **)malloc(sizeof(char *) * (wc + 1))))
		return (NULL);
	while (row < wc)
	{
		if (!(res[row] = (char *)malloc(sizeof(char) * (ft_word_len(str)))))
			exit(2);
		col = 0;
		while (!ft_space(*str))
			str++;
		while (*str && ft_space(*str))
			res[row][col++] = *str++;
		res[row][col] = '\0';
		row++;
	}
	res[row] = NULL;
	return (res);
}

char	**ft_cmd_split(char *str)
{
	char **res;

	if (!str)
		return (NULL);
	if (!(res = ft_word_eject((char *)str)))
		exit(2);
	return (res);
}

int		ft_word_count(char *str)
{
	int res;

	res = 0;
	while (*str)
	{
		while (!ft_space(*str))
			str++;
		if (*str)
		{
			res++;
			while (*str && ft_space(*str))
				str++;
		}
	}
	return (res);
}

int		ft_word_len(char *str)
{
	int res;

	res = 0;
	while (!ft_space(*str))
		str++;
	while (*str && (ft_space(*str)))
	{
		res++;
		str++;
	}
	return (res);
}
