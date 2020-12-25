#include "minishell.h"

int	ft_redirect(char **cmd_prm, char ***env, int in_fd)
{
	int		res;
	int		redirection_symbol;
	char	*redirection_file;

	in_fd = 0;
	res = 0;
	redirection_symbol = ft_search_redirect_symbol(cmd_prm);
	redirection_file = cmd_prm[redirection_symbol + 1];
	ft_redirect_openfile(redirection_file, in_fd);
	cmd_prm[redirection_symbol] = 0;
	return (ft_exe_notbuiltin(env, cmd_prm, res));
}
