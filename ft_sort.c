/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 11:57:29 by fdikilu           #+#    #+#             */
/*   Updated: 2017/04/05 11:59:00 by fdikilu          ###   ########.fr       */
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
			if (ft_strcmp(l_dir->content, tmp->content) > 0)
				ft_content_swap(l_dir, tmp);
			tmp = tmp->next;
		}
		ft_ascii_sort(l_dir->next);
	}
}
