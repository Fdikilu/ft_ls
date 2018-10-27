/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 00:30:26 by fdikilu           #+#    #+#             */
/*   Updated: 2018/10/27 21:07:41 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
		if (!(*l_d = listdir(av, fd, l_d)))
		{
			if (closedir(fd) == -1)
				perror("closedir");
			return (1);
		}
	}
	else
		return (0);
	return (1);
}

t_ldir			*ft_parse(int ac, char **av, unsigned char *flags)
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
			ft_isnotdir(*av, &l_file);
		++av;
	}
	if ((!l_file && !l_dir) && (ac == 1))
	{
		if (!(fdir = opendir(".")))
			perror("opendir");
		l_dir = listdir(".", fdir, &l_dir);
	}
	if (l_file)
		ft_print_file(l_file, flags);
	return (l_dir);
}
