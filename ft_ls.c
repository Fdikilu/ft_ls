/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:04:09 by fdikilu           #+#    #+#             */
/*   Updated: 2018/10/31 00:30:14 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(t_ldir *l_dir, unsigned char fl)
{
	DIR		*fd;
	t_list	*l_indir;
	t_list	*tmp;
	t_ldir	*l_rec;
	char	*ndir;

	l_rec = NULL;
	while (l_dir)
	{
		if (!(l_indir = ft_readdir(l_dir->f_dir, l_dir->name)))
			return ;
		tmp = l_indir;
		ft_sort(l_indir, fl);
		printf("\n%s:\n", l_dir->name);
		//affichage total ??? pour l'otion -l st_blocks
		while (tmp)
		{
			printf("%s\n", ((t_info *)tmp->content)->name);//ft_display(tmp, fl);
			if ((ft_strcmp(((t_info *)tmp->content)->name, ".") != 0) &&
				(ft_strcmp(((t_info *)tmp->content)->name, "..") != 0))
			{
				ndir = concat(l_dir->name, ((t_info *)tmp->content)->name);
				if (fl & FLAG_UPR && (fd = opendir(ndir)))
					if (!(l_rec = listdir(ndir, fd, &l_rec)))
						return ;
			}
			tmp = tmp->next;
		}
		ft_lstclr(&l_indir);
		if (fl & FLAG_UPR)
			while (l_rec)
			{
				ft_ls(l_rec, fl);
				l_rec = l_rec->next;
			}
		if (closedir(l_dir->f_dir) == -1)
			perror("closedir");
		l_dir = l_dir->next;
	}
}

int	main(int ac, char **av)
{
	t_ldir			*l_dir;
	unsigned char	flags;

	flags = NO_FLAG;
	if (!(l_dir = ft_parse(ac, av, &flags)))
		return (0);
	ft_ls(l_dir, flags);
	return (0);
}
