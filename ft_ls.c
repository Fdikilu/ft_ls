/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:04:09 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/07 22:05:52 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_indir(t_ldir *d, t_list *l, unsigned char fl, t_ldir **rec)
{
	DIR		*fd;
	char	*ndir;
	int		size[5];

	ft_sort(l, fl);
	(fl & FLAG_L) ? l_option(l, size) : 0;
	if (fl & FLAG_L)
		ft_blocks(l, fl);
	while (l)
	{
		ft_display(l->content, fl, size);
		if ((ft_strcmp(((t_info *)l->content)->name, ".") != 0) &&
			(ft_strcmp(((t_info *)l->content)->name, "..") != 0))
		{
			ndir = concat(d->name, ((t_info *)l->content)->name);
			if (fl & FLAG_UPR && (fd = opendir(ndir)))
				if (!(*rec = listdir(ndir, fd, rec)))
					return ;
		}
		l = l->next;
	}
	ft_putchar('\n');
}

void		ft_ls(t_ldir *l_dir, unsigned char fl, int l)
{
	t_list	*l_indir;
	t_ldir	*l_rec;

	l_rec = NULL;
	while (l_dir)
	{
		if (!(l_indir = ft_readdir(l_dir->f_dir, l_dir->name)))
			return ;
		if (l)
		{
			ft_putstr(l_dir->name);
			ft_putstr(":\n");
		}
		ft_indir(l_dir, l_indir, fl, &l_rec);
		ft_lstclr(&l_indir);
		if (fl & FLAG_UPR)
			while (l_rec)
			{
				ft_ls(l_rec, fl, 1);
				l_rec = l_rec->next;
			}
		if (closedir(l_dir->f_dir) == -1)
			perror("closedir");
		l_dir = l_dir->next;
	}
}

int			main(int ac, char **av)
{
	t_ldir			*l_dir;
	unsigned char	flags;

	flags = NO_FLAG;
	if (!(l_dir = ft_parse(ac, av, &flags)))
	{
		if (flags & FLAG_ERR)
		{
			ft_putstr("ft_ls: illegal option -- -\n");
			ft_putstr("usage: [-GRalrt] [file ...]\n");
			//free l_free
		}
		return (0);
	}
	ft_ls(l_dir, flags, 0);
	return (0);
}
