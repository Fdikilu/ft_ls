/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:40:50 by fdikilu           #+#    #+#             */
/*   Updated: 2018/10/25 20:41:45 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_print_file(t_list *l_file, unsigned char *flags)
{
	t_info	*tmp;

	if (*flags & FLAG_R && !(*flags & FLAG_T))
		ft_ascii_sortr(l_file);
	else if (*flags & FLAG_T && !(*flags & FLAG_R))
		ft_ascii_sort_time(l_file);
	else if (*flags & FLAG_T && *flags & FLAG_R)
		ft_ascii_sort_timer(l_file);
	else
		ft_ascii_sort(l_file);
	if (*flags & FLAG_L)
	{
		while (l_file)
		{
			tmp = l_file->content;
			printf("%s %d %s %s", tmp->rights, tmp->s_st.st_nlink, tmp->pwd->pw_name, tmp->grp->gr_name);
			printf(" %lld %s %s\n", tmp->s_st.st_size, tmp->time, tmp->name);
			l_file = l_file->next;
		}
	}
	else
	{
		while (l_file->next)
		{
			printf("%s\t", ((t_info *)l_file->content)->name);
			l_file = l_file->next;
		}
		printf("%s\n", ((t_info *)l_file->content)->name);
	}
}