/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 02:34:30 by fdikilu           #+#    #+#             */
/*   Updated: 2018/10/25 14:42:29 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_list			*tmp;
	t_ldir			*l_dir;
	unsigned char	flags;

	flags = NO_FLAG;
	if (ac < 1)
		return (0);
	if (!(l_dir = ft_parse(ac, av, &flags)))
		return (0);
	while (l_dir)
	{
		if (!(tmp = ft_readdir(l_dir->f_dir)))
			printf("nom %s\nfd %d\n", l_dir->name, (int)l_dir->f_dir);
		while (tmp)
		{
			printf("%s %s\n", ((t_info *)tmp->content)->rights, ((t_info *)tmp->content)->name);
			tmp = tmp->next;
		}
		l_dir = l_dir->next;
		free((void *)tmp);
	}
	return (0);
}
