/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:57:15 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/18 18:57:32 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	rec_free(t_ldir *rec)
{
	t_ldir	*tmp;

	while (rec)
	{
		tmp = rec;
		rec = rec->next;
		free((void *)tmp->name);
		free((void *)tmp);
	}
}

void	tab_free(char **tab)
{
	free((void *)tab[0]);
	free((void *)tab[1]);
	free((void *)tab);
}

void	lindir_free(t_list *l_indir)
{
	t_list	*tmp;

	while (l_indir)
	{
		tmp = l_indir;
		l_indir = l_indir->next;
		free((void *)((t_info *)tmp->content)->path);
		free((void *)tmp->content);
		free((void *)tmp);
	}
}
