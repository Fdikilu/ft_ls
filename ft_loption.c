/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:47:57 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/07 17:48:24 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	l_option(t_list *l_indir, int size[5])
{
	t_info	*tmp;
	int		i;

	i = 5;
	while (i--)
		size[i] = 0;
	while (l_indir)// remplacer les ft_itoa par un truc sans leaks
	{
		tmp = l_indir->content;
		i = ft_strlen(ft_itoa(tmp->s_st.st_nlink));
		size[0] = (size[0] < i) ? i : size[0];
		i = ft_strlen(tmp->pwd->pw_name);
		size[1] = (size[1] < i) ? i : size[1];
		i = ft_strlen(tmp->grp->gr_name);
		size[2] = (size[2] < i) ? i : size[2];
		if (tmp->rights[0] == 'c' || tmp->rights[0] == 'b')
		{
			i = ft_strlen(ft_itoa(major(tmp->s_st.st_rdev)));
			size[3] = (size[3] < i) ? i : size[3];
		}
		if (tmp->rights[0] == 'c' || tmp->rights[0] == 'b')
		{
			i = ft_strlen(ft_itoa(minor(tmp->s_st.st_rdev)));
			size[4] = (size[4] < i) ? i : size[4];
		}
		else
		{
			i = ft_strlen(ft_itoa(tmp->s_st.st_size));
			size[4] = (size[4] < i) ? i : size[4];
		}
		l_indir = l_indir->next;
	}
}
