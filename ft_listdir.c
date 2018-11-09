/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 18:03:11 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/08 23:49:17 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ldir	*listdir(char *s, t_ldir **l_dir, struct stat s_st)
{
	t_ldir	*new;
	t_ldir	*tmp;

	if (!(*l_dir))
	{
		if (!(*l_dir = (t_ldir *)malloc(sizeof(**l_dir))))
			return (NULL);
		(*l_dir)->name = s;
		(*l_dir)->s_st = s_st;
		(*l_dir)->next = NULL;
	}
	else
	{
		tmp = *l_dir;
		while (tmp->next)
			tmp = tmp->next;
		if (!(new = (t_ldir *)malloc(sizeof(*new))))
			return (NULL);
		new->name = s;
		new->s_st = s_st;
		new->next = NULL;
		tmp->next = new;
	}
	return (*l_dir);
}
