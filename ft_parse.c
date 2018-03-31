/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 00:30:26 by fdikilu           #+#    #+#             */
/*   Updated: 2018/03/31 16:42:42 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		flags_on(unsigned char *tmp, int c)
{
	if (c == 'l')
		*tmp |= FLAG_L;
	else if (c == 'R')
		*tmp |= FLAG_UPR;
	else if (c == 'a')
		*tmp |= FLAG_A;
	else if (c == 'r')
		*tmp |= FLAG_R;
	else if (c == 't')
		*tmp |= FLAG_T;
	else if (c == '-' && (*tmp == NO_FLAG))
		return ;
	else
	{
		*tmp |= FLAG_ERR;
		*tmp &= FLAG_ERR;
		return ;
	}
}

static void		init_flags(char *s, unsigned char *flags)
{
	unsigned char	tmp;

	++s;
	if (*s == '\0')
	{
		*flags |= FLAG_ERR;
		return ;
	}
	tmp = NO_FLAG;
	while (*s)
	{
		flags_on(&tmp, *s);
		++s;
	}
	*flags |= tmp;
}

static t_ldir	*parse(char *s, DIR *fdir, t_ldir **l_dir)
{
	t_ldir	*new;
	t_ldir	*tmp;

	if (!(*l_dir))
	{
		if (!(*l_dir = (t_ldir *)malloc(sizeof(**l_dir))))
			return (NULL);
		(*l_dir)->name = s;
		(*l_dir)->f_dir = fdir;
		(*l_dir)->next = NULL;
	}
	else
	{
		tmp = *l_dir;
		while (tmp->next)
			tmp = tmp->next;
		if (!(new = (t_ldir *)malloc(sizeof(*new))))
			return (NULL);
		new->name = s;
		new->f_dir = fdir;
		new->next = NULL;
		tmp->next = new;
	}
	return (*l_dir);
}

static int		norme(char *av, unsigned char *fl, t_ldir **l_d, DIR *fd)
{
	if (*fl & FLAG_ERR || (*av == '-' && ft_strlen(av) == 1))
	{
		printf("usage: [-lRart] [file ...]\n");
		return (1);
	}
	else if (*av == '-')
		init_flags(av, fl);
	else if ((fd = opendir(av)))
	{
		if (!(*l_d = parse(av, fd, l_d)))
		{
			if ((closedir(fd) == -1))
				perror("closedir");
			return (1);
		}
		if ((closedir(fd) == -1))
		{
			perror("closedir");
			return (1);
		}
	}
	else
		return (0);
	return (1);
}

t_ldir			*ft_parse(char **av, unsigned char *flags)
{
	DIR		*fdir;
	t_list	*l_file;
	t_ldir	*l_dir;

	++av;
	fdir = NULL;
	l_dir = NULL;
	l_file = NULL;
	while (*av)
	{
		if (!(norme(*av, flags, &l_dir, fdir)))
			ft_isnotdir(*av, &l_file, flags);
		++av;
	}
	if (!l_file && !l_dir)
	{
		if (!(fdir = opendir(".")))
			perror("opendir");
		l_dir = parse(".", fdir, &l_dir);
		if ((closedir(fdir) == -1))
			perror("closedir");
	}
	if (l_file)
		ft_print_file(l_file, flags);
	return (l_dir);
}
