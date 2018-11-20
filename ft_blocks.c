/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blocks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:23:46 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/20 23:29:55 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_blocks(t_list *l_indir, unsigned int flags)
{
	int		nb_blocks;

	nb_blocks = 0;
	while (l_indir)
	{
		if (((t_info *)l_indir->content)->name[0] != '.')
			nb_blocks += ((t_info *)l_indir->content)->s_st.st_blocks;
		else if (flags & FLAG_A)
			nb_blocks += ((t_info *)l_indir->content)->s_st.st_blocks;
		l_indir = l_indir->next;
	}
	ft_putstr("total ");
	ft_putnbr(nb_blocks);
	ft_putchar('\n');
}
