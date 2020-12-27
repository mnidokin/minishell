#include "minishell.h"

int	ft_search_char(char *str, char symbol)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == symbol)
			return (EXIT_SUCCESS);
		index++;
	}
	return (EXIT_FAILURE);
}

int	ft_search_redirect(char **cmd)
{
	int	index;

	index = 0;
	while (cmd[index])
	{
		if (ft_search_char(cmd[index], '<') == EXIT_SUCCESS ||
		ft_search_char(cmd[index], '>') == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
		index++;
	}
	return (EXIT_FAILURE);
}

int	ft_search_redirect_symbol(char **cmd)
{
	int	index;

	index = 0;
	while (cmd[index])
	{
		if (ft_search_char(cmd[index], '<') == EXIT_SUCCESS ||
		ft_search_char(cmd[index], '>') == EXIT_SUCCESS)
			return (index);
		index++;
	}
	return (EXIT_FAILURE);
}

void	ft_redirect_openfile(char *file_name, int redirection)
{
	int	fd;

	if (redirection == REDIRECT_STD_OUTPUT_ADD)
	{
		fd = open(file_name, O_CREAT | O_RDWR | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
		dup2(fd, 1);
	}
	else if (redirection == REDIRECT_STD_INPUT)
	{
		fd = open(file_name, O_RDONLY);
		dup2(fd, 0);
	}
	if (redirection == REDIRECT_STD_OUTPUT)
	{
		fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
		dup2(fd, 1);
	}
	close(fd);
}

int	ft_search_symbol(char **str_arr, char *symbol)
{
	int index;

	index = 0;
	while (str_arr[index])
	{
		if (ft_strequ(str_arr[index], symbol))
			return (EXIT_SUCCESS);
		index++;
	}
	return (EXIT_FAILURE);
}

int	ft_redirect_isinput(char **cmd)
{
	int index;

	index = 0;
	while (cmd[index])
	{
		if (ft_strequ(cmd[index], "<"))
			return (EXIT_SUCCESS);
		index++;
	}
	return (EXIT_FAILURE);
}

int	ft_redirect_check(char *cmd_line)
{
	int index;

	index = 0;
	while (cmd_line[index])
	{
		if (cmd_line[index] == '>' || cmd_line[index] == '<')
		{
			return (EXIT_SUCCESS);
		}
		index++;
	}
	return (EXIT_FAILURE);
}
