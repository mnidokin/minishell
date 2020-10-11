#include "minishell.h"

void    ft_free(t_envir **envir)
{
    t_envir *tmp;

    while (*envir)
    {
        tmp = (*envir)->next;
        ft_strdel(&((*envir)->name));
        //ft_strdel(&(*envir)->value);
        //ft_memdel((void **)envir);
        (*envir) = tmp;
    }
}