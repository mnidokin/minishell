#include "minishell.h"

int	ft_redirect(char **cmd_prm, char ***env, int in_fd)
{
	int		res;
	int		redirection_symbol;
	char	*redirection_file;

	res = 0;
	in_fd = STDIN_FILENO;
	redirection_symbol = ft_search_redirect_symbol(cmd_prm);
	redirection_file = cmd_prm[redirection_symbol + 1];
	ft_redirect_openfile(redirection_file, in_fd);
	cmd_prm[redirection_symbol] = 0;
	res = ft_exe_cve(cmd_prm[0], &cmd_prm[0], *env);
	return (res);
}
