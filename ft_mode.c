/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 05:01:41 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/20 23:36:22 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	ft_type(struct stat stat_m)
{
	if (S_ISREG(stat_m.st_mode))
		return ('-');
	else if (S_ISDIR(stat_m.st_mode))
		return ('d');
	else if (S_ISCHR(stat_m.st_mode))
		return ('c');
	else if (S_ISBLK(stat_m.st_mode))
		return ('b');
	else if (S_ISFIFO(stat_m.st_mode))
		return ('p');
	else if (S_ISLNK(stat_m.st_mode))
		return ('l');
	else if (S_ISSOCK(stat_m.st_mode))
		return ('s');
	else
		return ('e');
}

static char	fstgrp(struct stat stat_m)
{
	if ((stat_m.st_mode & S_ISUID) || (stat_m.st_mode & S_ISGID))
	{
		if (stat_m.st_mode & S_IXUSR)
			return ('s');
		else
			return ('S');
	}
	else
	{
		if (stat_m.st_mode & S_IXUSR)
			return ('x');
		else
			return ('-');
	}
}

static char	thrdgrp(struct stat stat_m)
{
	if ((stat_m.st_mode & S_ISVTX))
	{
		if ((stat_m.st_mode & S_IXOTH) || (stat_m.st_mode & S_IROTH))
			return ('t');
		else
			return ('T');
	}
	else
	{
		if ((stat_m.st_mode & S_IXOTH))
			return ('x');
		else
			return ('-');
	}
}

void		ft_mode(struct stat stat_m, char rights[11])
{
	rights[0] = ft_type(stat_m);
	rights[1] = (stat_m.st_mode & S_IRUSR) ? 'r' : '-';
	rights[2] = (stat_m.st_mode & S_IWUSR) ? 'w' : '-';
	rights[3] = fstgrp(stat_m);
	rights[4] = (stat_m.st_mode & S_IRGRP) ? 'r' : '-';
	rights[5] = (stat_m.st_mode & S_IWGRP) ? 'w' : '-';
	rights[6] = (stat_m.st_mode & S_IXGRP) ? 'x' : '-';
	rights[7] = (stat_m.st_mode & S_IROTH) ? 'r' : '-';
	rights[8] = (stat_m.st_mode & S_IWOTH) ? 'w' : '-';
	rights[9] = thrdgrp(stat_m);
	rights[10] = '\0';
}
