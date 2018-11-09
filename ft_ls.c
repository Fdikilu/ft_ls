/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:04:09 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/09 22:15:41 by fdikilu          ###   ########.fr       */
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
				return ;
			if (!(*rec = listdir(ndir, rec, info->s_st)))
				return ;
		}
	}
}

static void	ft_indir(t_ldir *d, t_list *l, unsigned char fl, t_ldir **rec)
{
	DIR			*flux_dir;
	int			size[5];
	t_list		*tmp;

	flux_dir = NULL;
	if (!(l = ft_readdir(d, &flux_dir, fl)))
		return ;
	ft_sort(l, fl);
	(fl & FLAG_L) ? l_option(l, size) : 0;
	(fl & FLAG_L) ? ft_blocks(l, fl) : 0;
	tmp = l;
	while (tmp)
	{
		ft_display(tmp->content, fl, size);
		ft_rec(d->name, tmp->content, fl, rec);
		tmp = tmp->next;
	}
	ft_lstclr(&l);
	if (closedir(flux_dir) == -1)
		perror("ft_ls");
}

void		ft_ls(t_ldir *l_dir, unsigned char fl, int frst)
{
	t_list	*l_indir;
	t_ldir	*l_rec;

	l_indir = NULL;
	l_rec = NULL;
	if (frst)
	{
		ft_putstr(l_dir->name);
		ft_putstr(":\n");
	}
	ft_indir(l_dir, l_indir, fl, &l_rec);
	ft_putchar('\n');
	if (fl & FLAG_UPR)
		while (l_rec)
		{
			ft_ls(l_rec, fl, 1);
			l_rec = l_rec->next;
		}
	l_dir = l_dir->next;
}

int			main(int ac, char **av)
{
	int				frst;
	t_ldir			*l_dir;
	unsigned char	flags;

	(void)ac;
	frst = 0;
	flags = NO_FLAG;
	if (!(l_dir = ft_parse(av, &flags)))
	{
		if (flags & FLAG_ERR)
		{
			ft_putstr("ft_ls: illegal option -- -\n");
			ft_putstr("usage: [-GRalrt] [file ...]\n");
			//free l_dir
		}
		return (0);
	}
	while (l_dir)
	{
		ft_ls(l_dir, flags, frst);
		frst = 1;
		l_dir = l_dir->next;
	}
	return (0);
}
