/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:04:09 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/13 22:36:23 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_rec(char *d, t_info *info, unsigned char fl, t_ldir **rec)
{
	char	*ndir;

	if ((ft_strcmp(info->name, ".") != 0) &&
		(ft_strcmp(info->name, "..") != 0))
	{
		if (!(ndir = concat(d, info->name)))
			return ;
		if (fl & FLAG_UPR && S_ISDIR(info->s_st.st_mode))
		{
			if (info->name[0] == '.' && !(fl & FLAG_A))
			{
				free((void *)ndir);
				return ;
			}
			if (!(*rec = listdir(ndir, rec, info->s_st)))
				return ;
		}
		else
			free((void *)ndir);
	}
}

static void	ft_indir(t_ldir *d, unsigned char fl, t_ldir **rec)
{
	DIR			*flux_dir;
	int			size[5];
	t_list		*tmp;
	t_list		*l_indir;

	flux_dir = NULL;
	if (!(l_indir = ft_readdir(d, &flux_dir, fl)))
		return ;
	ft_sort(l_indir, fl);
	(fl & FLAG_L) ? l_sizecolonne(l_indir, size) : 0;
	(fl & FLAG_L) ? ft_blocks(l_indir, fl) : 0;
	tmp = l_indir;
	while (tmp)
	{
		ft_display(tmp->content, fl, size);
		ft_rec(d->name, tmp->content, fl, rec);
		tmp = tmp->next;
	}
	ft_lstclr(&l_indir);
	if (closedir(flux_dir) == -1)
		perror("ft_ls");
}

void		ft_ls(t_ldir *l_dir, unsigned char fl, int frst)
{
	t_ldir	*l_rec;
	t_ldir	*tmp;

	l_rec = NULL;
	if (frst)
	{
		ft_putstr(l_dir->name);
		ft_putstr(":\n");
	}
	ft_indir(l_dir, fl, &l_rec);
	ft_putchar('\n');
	tmp = l_rec;
	if (fl & FLAG_UPR)
		while (l_rec)
		{
			ft_ls(l_rec, fl, 1);
			l_rec = l_rec->next;
		}
	if (tmp)
		rec_free(tmp);
	l_dir = l_dir->next;
}

int			main(int ac, char **av)
{
	int				frst;
	t_ldir			*tmp;
	t_ldir			*l_dir;
	unsigned char	flags;

	(void)ac;
	frst = 0;
	flags = NO_FLAG;
	if (!(l_dir = ft_parse(av, &flags)))
	{
		if (flags & FLAG_ERR)
			ft_putstr("ft_ls: illegal option\nusage: [-GRalrt] [file ...]\n");
		return (0);
	}
	while (l_dir)
	{
		tmp = l_dir;
		ft_ls(l_dir, flags, frst);
		frst = 1;
		l_dir = l_dir->next;
		free((void *)tmp);
	}
	return (0);
}
