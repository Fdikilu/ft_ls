/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 11:57:29 by fdikilu           #+#    #+#             */
/*   Updated: 2018/10/23 21:15:28 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ascii_sort(t_list *l_dir)
{
	t_list	*tmp;

	tmp = l_dir;
	if (!(l_dir->next))
		return ;
	else
	{
		while (tmp)
		{
			if (ft_strcmp(((t_info *)l_dir->content)->name,
				((t_info *)tmp->content)->name) > 0)
				ft_content_swap(l_dir, tmp);
			tmp = tmp->next;
		}
		ft_ascii_sort(l_dir->next);
	}
}

void		ft_ascii_sortr(t_list *l_dir)
{
	t_list	*tmp;

	tmp = l_dir;
	if (!(l_dir->next))
		return ;
	else
	{
		while (tmp)
		{
			if (ft_strcmp(((t_info *)l_dir->content)->name,
				((t_info *)tmp->content)->name) < 0)
				ft_content_swap(l_dir, tmp);
			tmp = tmp->next;
		}
		ft_ascii_sortr(l_dir->next);
	}
}

void		ft_ascii_sort_time(t_list *l_dir)
{
	t_list	*tmp;

	tmp = l_dir;
	if (!(l_dir->next))
		return ;
	else
	{
		while (tmp)
		{
			if (ft_timecmp(((t_info *)l_dir->content)->s_st,
				((t_info *)tmp->content)->s_st) < 0)
				ft_content_swap(l_dir, tmp);
			tmp = tmp->next;
		}
		ft_ascii_sort_time(l_dir->next);
	}
}

void		ft_ascii_sort_timer(t_list *l_dir)
{
	t_list	*tmp;

	tmp = l_dir;
	if (!(l_dir->next))
		return ;
	else
	{
		while (tmp)
		{
			if (ft_timecmp(((t_info *)l_dir->content)->s_st,
				((t_info *)tmp->content)->s_st) > 0)
				ft_content_swap(l_dir, tmp);
			tmp = tmp->next;
		}
		ft_ascii_sort_timer(l_dir->next);
	}
}
