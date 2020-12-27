#include "minishell.h"

int	ft_redirect(char **cmd_prm, char ***env, int fd)
{
	int		res;
	int		redirection_symbol;
	char	*redirection_file;

	fd = REDIRECT_STD_OUTPUT;
	res = 0;
	redirection_symbol = ft_search_redirect_symbol(cmd_prm);
	redirection_file = cmd_prm[redirection_symbol + 1];
	if (ft_redirect_isinput(cmd_prm) == EXIT_SUCCESS)
		fd = REDIRECT_STD_INPUT;
	ft_redirect_openfile(redirection_file, fd);
	cmd_prm[redirection_symbol] = 0;
	return (ft_exe_notbuiltin(env, cmd_prm, res));
}
