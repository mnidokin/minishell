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
	if (ft_search_symbol(cmd_prm, "<") == EXIT_SUCCESS)
		fd = REDIRECT_STD_INPUT;
	else if (ft_search_symbol(cmd_prm, ">>") == EXIT_SUCCESS)
		fd = REDIRECT_STD_OUTPUT_ADD;
	if (ft_search_symbol(cmd_prm, "<<") == EXIT_SUCCESS)
	{
		ft_here_doc(cmd_prm);
	}
	else if (ft_is_file_descriptor_aggr(cmd_prm) == 1)
	{
		if (ft_manage_file_descriptors(cmd_prm) == -1)
			return (-1);
	}
	ft_redirect_openfile(redirection_file, fd);
	cmd_prm[redirection_symbol] = 0;
	return (ft_exe_notbuiltin(env, cmd_prm, res));
}
