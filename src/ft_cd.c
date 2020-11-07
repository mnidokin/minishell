#include "minishell.h"

int	ft_builtin_cd(char **cmd, char ***env)
{
	char *home_pth;

	cmd += 1;
	ft_get_env(*env, "HOME", &home_pth);
	if (!cmd || ft_strequ(cmd[0], "--"))
	return (0);
}

int ft_ch_dr(char *pth)
{
	char *cwd;
	char buf[5120];

	cwd = getcwd();
	return (0);
}
