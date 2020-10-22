#include "minishell.h"

void	ft_free(t_envir **envir)
{
	t_envir	*tmp;

    while (*envir)
    {
        tmp = (*envir)->next;
        ft_strdel(&((*envir)->name));
        (*envir) = tmp;
    }
}