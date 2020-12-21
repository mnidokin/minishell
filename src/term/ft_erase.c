/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:25:32 by mozzart           #+#    #+#             */
/*   Updated: 2020/12/21 00:11:52 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

size_t	ft_erase(t_clist *lst, t_ttyfd *fd, t_screen *scrn)
{
	if (lst)
	{
		if (lst->start == lst->current)
			lst->start = lst->current->next;
		if (lst->end == lst->current)
			lst->end = lst->current->prev;
		lst->current = lst->current->next;
		lst->erase(lst->current->prev);
	}
	ft_term_send_command("cl");
	if (lst)
		if (--lst->len)
		{
			lst->print(lst, fd, scrn);
			lst->current->activate(lst->current, fd);
		}
	if (lst)
		return (lst->len);
	else
		return (0);
}
