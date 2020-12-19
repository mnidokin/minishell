/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:23:04 by tvanessa          #+#    #+#             */
/*   Updated: 2020/12/19 06:28:27 by tvanessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLST_H
# define FT_DLST_H
# ifndef LIBFT_H
#  include "libft.h"
# endif
# ifndef FT_TYPES_H
#  include "ft_types.h"
# endif

typedef struct					s_double_linked_list
{
	void						*content;
	size_t						size;
	struct s_double_linked_list	*prev;
	struct s_double_linked_list	*next;
}								t_double_linked_list;
typedef t_double_linked_list	t_dlist;

enum							e_dlst_errs
{
	E_DLST_SUCCESS,
	E_DLST_MALLOC,
	E_DLST_NULLPTR
};

t_dlist	*ft_dlst_new(void *data, size_t size);
t_dlist	*ft_dlst_append(t_dlist *list, void *data, size_t size);
t_uc	ft_dlst_clear(t_dlist *list);
t_uc	ft_dlst_del_first(t_dlist *list);
t_uc	ft_dlst_del(t_dlist *list);

#endif