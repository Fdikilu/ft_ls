/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:26:54 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/18 20:09:41 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_info	*ft_info(struct dirent *struct_dir, char *path)
{
	t_info			*info;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	if (lstat(path, &info->s_st) == 0)
	{
		info->time = ft_time(info->s_st);
		ft_mode(info->s_st, info->rights);
		if (info->rights[0] == 'l')
		{
			info->buf = ft_strnew(1024);
			if (readlink(path, info->buf, 1024) == -1)
				perror("readlink");
		}
		else
			info->buf = NULL;
		info->pwd = ft_pwd(info->s_st);
		info->grp = ft_grp(info->s_st);
	}
	ft_strcpy(info->name, struct_dir->d_name);
	info->path = path;
	return (info);
}

static int		set_indir(unsigned char flags, struct dirent *s_dir,
	t_ldir *dir, t_list **l_indir)
{
	t_info			*info;

	if (errno == 13 && !(dir->s_st.st_mode & S_IWUSR) && (flags & FLAG_L))
	{
		if (*l_indir)
			lindir_free(*l_indir);
		return (0);
	}
	if (!(info = ft_info(s_dir, concat(dir->name, s_dir->d_name))))
		return (0);
	if (*l_indir)
		ft_lstadd(l_indir, ft_lstnew((t_info *)info, sizeof(*info)));
	else
		*l_indir = ft_lstnew((t_info *)info, sizeof(*info));
	free((void *)info);
	return (1);
}

t_list			*ft_readdir(t_ldir *dir, DIR **flux_dir, unsigned char flags)
{
	t_list			*l_indir;
	struct dirent	*s_dir;

	l_indir = NULL;
	if (!(*flux_dir = opendir(dir->name)))
	{
		ft_putstr("ft_ls: ");
		perror(dir->name);
		return (NULL);
	}
	while ((s_dir = readdir(*flux_dir)))
		if (set_indir(flags, s_dir, dir, &l_indir) == 0)
		{
			if (closedir(*flux_dir) == -1)
				perror("closedir");
			return (NULL);
		}
	return (l_indir);
}
