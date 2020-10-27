#include "minishell.h"

t_envir		*ft_envir_lst(char **src, char ***env)
{
	t_envir *res;
	t_envir *new;
	int		i;

	i = 0;
	res = NULL;
	new = NULL;
	if (!(*env = ft_memalloc(sizeof(char *) * ft_envir_strcount(src) + 1)))
		exit(2);
	while (src[i])
	{
		if (!((*env)[i] = ft_strdup(src[i])))
			exit(2);
		new = ft_envir_init(src[i]);
		ft_envir_shllchange(new);
		ft_envir_lstaddback(&res, new);
		i++;
	}
	(*env)[i] = NULL;
	return (res);
}

t_envir		*ft_envir_init(char *str)
{
	char	**n_v;
	t_envir *res;

	res = NULL;
	n_v = NULL;
	if (!(res = ft_memalloc(sizeof(t_envir))))
		exit(2);
	if (!(n_v = ft_strsplit(str, '=')))
		exit(2);
	if (!(res->name = ft_strdup(n_v[0])))
		exit(2);
	if (!(res->value = ft_strdup(n_v[1])))
		exit(2);
	res->next = NULL;
	ft_strdel(&n_v[0]);
	ft_strdel(&n_v[1]);
	free(n_v);
	return (res);
}

void		ft_envir_lstaddback(t_envir **envir, t_envir *new)
{
	t_envir *tmp;

	if (*envir)
	{
		tmp = *envir;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*envir = new;
}

void		ft_envir_shllchange(t_envir *envir)
{
	char *pwd;

	pwd = ft_pwd(NULL);
	if (!ft_strcmp(envir->name, "SHELL"))
		envir->value = ft_strdup(pwd);
}

int			ft_envir_strcount(char **str)
{
	int	res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}
