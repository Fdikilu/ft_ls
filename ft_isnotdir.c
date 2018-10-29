/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnotdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:16:37 by fdikilu           #+#    #+#             */
/*   Updated: 2018/10/29 17:11:25 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_info	*create_info(char *path)
{
	t_info		*info;
	struct stat	struct_stat;

	if (lstat(path, &struct_stat) == -1)
	{
		perror("lstat");
		return (NULL);
	}
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	ft_strcpy(info->name, path);
	info->path = NULL;
	info->s_st = struct_stat;
	ft_mode(struct_stat, info->rights);
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

void			ft_isnotdir(char *name, t_list **lfile)
{
	struct dirent	*struct_dir;
	DIR				*flux_dir;
	t_info			*tmp;
	char			**tab;

	tmp = NULL;
	if (!(tab = scut(name, ft_strlen(name), 0)))
		if (!(tab = scut2(name)))
			return ;
	if (!(flux_dir = opendir(tab[0])))
	{
		printf("ft_ls: %s: Not a directory\n", name);
		return ;
	}
	while ((struct_dir = readdir(flux_dir)))
		if (ft_strcmp(struct_dir->d_name, tab[1]) == 0)
		{
			if (!(tmp = create_info(name)))
				return ;
			if (!(*lfile) && (*lfile = ft_lstnew((t_info *)tmp, sizeof(*tmp))))
				return ;
			else
			{
				ft_lstadd(lfile, ft_lstnew((t_info *)tmp, sizeof(*tmp)));
				return ;
			}
		}
	printf("ft_ls: %s: No such file or directory\n", name);
}
