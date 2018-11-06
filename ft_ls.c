/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:04:09 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/06 22:33:53 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	l_option(t_list *l_indir, int size[5])
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

void		ft_ls(t_ldir *l_dir, unsigned char fl)
{
	DIR		*fd;
	t_list	*l_indir;
	t_list	*tmp;
	t_ldir	*l_rec;
	char	*ndir;
	int		size[5];

	l_rec = NULL;
	while (l_dir)
	{
		if (!(l_indir = ft_readdir(l_dir->f_dir, l_dir->name)))
			return ;
		tmp = l_indir;
		ft_sort(l_indir, fl);
		(fl & FLAG_L) ? l_option(l_indir, size) : 0;
		printf("\n%s:\n", l_dir->name);
		//affichage total ??? pour l'otion -l st_blocks
		while (tmp)
		{
			ft_display(tmp->content, fl, size);
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

int			main(int ac, char **av)
{
	t_ldir			*l_dir;
	unsigned char	flags;

	flags = NO_FLAG;
	if (!(l_dir = ft_parse(ac, av, &flags)))
		return (0);
	if (flags & FLAG_ERR)
	{
		ft_putstr("ft_ls: illegal option -- -\n");
		ft_putstr("usage: [-lRartG] [file ...]\n");
		//free l_dir
		return (0);
	}
	ft_ls(l_dir, flags);
	return (0);
}
