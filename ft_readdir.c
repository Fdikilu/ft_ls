/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:57:09 by fdikilu           #+#    #+#             */
/*   Updated: 2018/10/26 19:30:15 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_info	*ft_info(struct dirent *struct_dir, char *path)
{
	t_info			*info;
	
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	if (stat(path, &info->s_st) == -1)
		perror("stat");
	info->name = struct_dir->d_name;
	info->path = path;
	info->time = ft_time(info->s_st);
	ft_mode(info->s_st, info->rights);
	info->pwd = ft_pwd(info->s_st);
	info->grp = ft_grp(info->s_st);
	return (info);
}

static char		*concat(char *ndir, char *nfile)
{
	char	*path;

	if (!(path = ft_strnew(ft_strlen(ndir) + ft_strlen(nfile) + 1)))
		return (NULL);
	ft_strcpy(path, ndir);
	ft_strcat(path, "/");
	ft_strcat(path, nfile);
	return (path);
}

t_list	*ft_readdir(DIR *flux_dir, char *ndir)
{
	t_info			*info;
	t_list			*l_indir;
	struct dirent	*struct_dir;

	l_indir = NULL;
	while ((struct_dir = readdir(flux_dir)))
	{
		if (!(info = ft_info(struct_dir, concat(ndir, struct_dir->d_name))))
			return (NULL);
		if (l_indir)
			ft_lstadd(&l_indir, ft_lstnew((t_info *)info, sizeof(*info)));
		else
			l_indir = ft_lstnew((t_info *)info, sizeof(*info));
	}
	return (l_indir);
}
