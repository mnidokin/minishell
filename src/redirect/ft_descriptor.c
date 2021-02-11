#include "minishell.h"

int	ft_manage_file_descriptors(char **cmd)
{
	int		descriptor_pos;
	char	*descriptor;
	int		fd;
	int		fd2;

	descriptor_pos = ft_get_file_descriptor_pos(cmd);
	descriptor = cmd[descriptor_pos];
	fd2 = descriptor[0] - '0';
	if (descriptor[ft_strlen(descriptor) - 1] == '-')
	{
		close(fd2);
		return (descriptor_pos);
	}
	if (cmd[descriptor_pos + 1] != NULL)
	{
		fd = open(cmd[descriptor_pos + 1], O_CREAT | O_RDWR | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	}
	else 
	{
		ft_putendl("21sh: parse error near \'\\n\'");
		close(fd2);
		return (-1);
	}
	dup2(fd, fd2);
	return (descriptor_pos);
}

int	ft_get_file_descriptor_pos(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (ft_isdigit(cmd[i][0]) && cmd[i][1] == '>')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_is_file_descriptor_aggr(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (ft_isdigit(cmd[i][0]) && cmd[i][1] == '>')
			return (1);
		i++;
	}
	return (0);
}
