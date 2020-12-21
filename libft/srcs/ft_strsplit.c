/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzart <mozzart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:30:56 by tvanessa          #+#    #+#             */
/*   Updated: 2020/10/21 20:17:45 by mozzart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char *s, char c)
{
	size_t	l;
	uint8_t	w;

	l = 0;
	w = 0;
	while (*s)
	{
		if (*s != c && !w && ++l)
			w = 1;
		else if (*s == c && w)
			w = 0;
		++s;
	}
	return (l);
}

static char		*ft_strndup(char *str, size_t l)
{
	char	*res;
	size_t	i;

	if (!(res = ft_strnew(l)))
		return (NULL);
	i = 0;
	while (i < l)
	{
		res[i] = str[i];
		++i;
	}
	res[i] = 0;
	return (res);
}

static char		*ft_get_word(char **str, char c)
{
	char	*res;

	res = ft_skip_char(str, c);
	*str = ft_strchr(res, c);
	if (*str - res)
		return (ft_strndup(res, *str ? *str - res : ft_strlen(res)));
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	l;
	char	**r;
	char	*st;

	if (!s)
		return (NULL);
	i = 0;
	r = NULL;
	st = (char*)s;
	l = ft_count_words(st, c);
	if (!(r = (char**)malloc(sizeof(char*) * (l + 1))))
		return (NULL);
	l = 0;
	while (st && *st)
	{
		if (!(r[l] = ft_get_word(&st, c)))
			return (ft_free((void**)&r));
		ft_skip_char(&st, c);
		++l;
	}
	r[l] = NULL;
	return (r);
}
