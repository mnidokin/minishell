#include "minishell.h"

int		ft_here_doc(char **cmd)
{
	int		fd[2];
	char	redirect_symbol;
	char	*eof_string;

	redirect_symbol = ft_search_symbol(cmd, "<<");
	eof_string = cmd[redirect_symbol + 2];
	pipe(fd);
	ft_here_doc_readline(fd[1], eof_string);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	if (cmd[redirect_symbol + 2] != NULL && cmd[redirect_symbol + 3] != NULL)
	{
		ft_here_doc_open_file(redirect_symbol, cmd);
	}
	return (redirect_symbol);
}

void	ft_here_doc_readline(int fd, char *eof_string)
{
	ssize_t	buf_len;
	char	buf[SIZE];
	char	*buf_arr[SIZE];
	int		iter;

	ft_memset(buf, 0, SIZE);
	ft_memset(buf_arr, 0, SIZE * sizeof(*buf_arr));
	iter = 0;
	ft_putstr(COLOR_GREEN);
	ft_putstr("heredoc > ");
	ft_putstr(COLOR_FLUSH);
	while ((buf_len = read(1, buf, SIZE)) > 0)
	{
		if (ft_strncmp(buf, eof_string, ft_strlen(buf) - 1) == 0)
		{
			break ;
		}
		else
		{
			ft_putstr(COLOR_GREEN);
			ft_putstr("heredoc > ");
			ft_putstr(COLOR_FLUSH);
			buf_arr[iter++] = ft_strdup(buf);
		}
		ft_memset(buf, 0, SIZE);
	}
	if (buf_len == 0)
		ft_putendl_fd("ERROR", 2);
	iter = 0;
	while (buf_arr[iter])
	{
		ft_putstr_fd(buf_arr[iter], fd);
		iter++;
	}
}

void	ft_here_doc_open_file(int redirection_symbol, char **cmd_prm)
{
	char	*file_name;
	int		fd;

	if (ft_strequ(cmd_prm[redirection_symbol + 2], ">"))
	{
		if (cmd_prm[redirection_symbol + 3] != NULL)
		{
			file_name = cmd_prm[redirection_symbol + 3];
			fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
			dup2(fd, 1);
		}
	}
	else if (ft_strequ(cmd_prm[redirection_symbol + 2], ">>"))
	{
		if (cmd_prm[redirection_symbol + 3] != NULL)
		{
			file_name = cmd_prm[redirection_symbol + 3];
			fd = open(file_name, O_CREAT | O_RDWR | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
			dup2(fd, 1);
		}
	}
}
