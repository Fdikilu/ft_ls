/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnotdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:16:37 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/18 00:08:52 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_info	*create_info(char *path)
{
	t_info		*info;
	struct stat	struct_stat;

	if (lstat(path, &struct_stat) == -1)
		return (NULL);
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	ft_strcpy(info->name, path);
	info->path = NULL;
	info->s_st = struct_stat;
	ft_mode(struct_stat, info->rights);
	if (info->rights[0] == 'l')
	{
		info->buf = ft_strnew(1024);
		if (readlink(path, info->buf, 1024) == -1)
			perror("readlink");
	}
	else
		info->buf = NULL;
	info->pwd = ft_pwd(struct_stat);
	info->grp = ft_grp(struct_stat);
	info->time = ft_time(struct_stat);
	return (info);
}

static char		**scut(char *name, int nlen, int i)
{
	char	**tab;

	while (name[nlen] != '/' && nlen > 0)
		nlen--;
	if ((nlen == 0) || !(tab = (char **)malloc(sizeof(char *) * 3)))
		return (NULL);
	if (!(tab[0] = ft_strnew(nlen)) ||
		!(tab[1] = ft_strnew(ft_strlen(name) - nlen)))
		return (NULL);
	while (nlen-- && (tab[0][i] = *name))
	{
		i++;
		name++;
	}
	name++;
	ft_strcpy(tab[1], name);
	tab[2] = 0;
	return (tab);
}

char			**scut2(char *name)
{
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * 3)))
		return (NULL);
	if ((!(tab[0] = ft_strnew(1))) ||
		!(tab[1] = ft_strnew(ft_strlen(name))))
		return (NULL);
	tab[0][0] = '.';
	ft_strcpy(tab[1], name);
	tab[2] = 0;
	return (tab);
}

static int		filedir(DIR **fdir, char **tab, t_list **lfile, char *name)
{
	t_info			*tmp;
	struct dirent	*struct_dir;

	tmp = NULL;
	while ((struct_dir = readdir(*fdir)))
	{
		if (errno == 13)
		{
			perror("ft_ls");
			closedir(*fdir);
			return (0);
		}
		if (ft_strcmp(struct_dir->d_name, tab[1]) == 0)
		{
			if (!(tmp = create_info(name)))
				return (0);
			if (!(*lfile))
				*lfile = ft_lstnew((t_info *)tmp, sizeof(*tmp));
			else
				ft_lstadd(lfile, ft_lstnew((t_info *)tmp, sizeof(*tmp)));
			free((void *)tmp);
			closedir(*fdir);
			return (0);
		}
	}
	closedir(*fdir);
	return (1);
}

int				ft_isnotdir(char *name, t_list **lfile)
{
	DIR				*flux_dir;
	char			**tab;

	if (!(tab = scut(name, ft_strlen(name), 0)))
		if (!(tab = scut2(name)))
			return (1);
	if (!(flux_dir = opendir(tab[0])))
	{
		tab_free(tab);
		ft_putstr("ft_ls: ");
		perror(name);
		return (0);
	}
	if (!(filedir(&flux_dir, tab, lfile, name)))
	{
		tab_free(tab);
		return (0);
	}
	tab_free(tab);//if rights[0] == 'l' ft_display(tout) || ft_ls /var
	ft_putstr("ft_ls: ");
	perror(name);
	return (0);
}
