/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:26:54 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/10 18:51:35 by fdikilu          ###   ########.fr       */
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

char			*concat(char *ndir, char *nfile)
{
	char	*path;

	if (!(path = ft_strnew(ft_strlen(ndir) + ft_strlen(nfile) + 1)))
		return (NULL);
	ft_strcpy(path, ndir);
	ft_strcat(path, "/");
	ft_strcat(path, nfile);
	return (path);
}

t_list			*ft_readdir(t_ldir *dir, DIR **flux_dir, unsigned char flags)
{
	t_info			*info;
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
	{
		if (errno == 13 && !(dir->s_st.st_mode & S_IWUSR) && (flags & FLAG_L))
			return (NULL);
		if (!(info = ft_info(s_dir, concat(dir->name, s_dir->d_name))))
			return (NULL);
		if (l_indir)
			ft_lstadd(&l_indir, ft_lstnew((t_info *)info, sizeof(*info)));
		else
			l_indir = ft_lstnew((t_info *)info, sizeof(*info));
	}
	return (l_indir);
}
