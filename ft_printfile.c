/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:40:50 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/10 22:56:21 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_print_file(t_list *l_file, unsigned char *flags)
{
	int		size[5];
	t_list	*tmp;

	(*flags & FLAG_L) ? l_sizecolonne(l_file, size) : 0;
	ft_sort(l_file, *flags);
	tmp = l_file;
	while (tmp)
	{
		ft_display(tmp->content, *flags, size);
		tmp = tmp->next;
	}
	ft_lstclr(&l_file);
}
