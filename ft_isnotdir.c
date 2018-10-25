/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnotdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:16:37 by fdikilu           #+#    #+#             */
/*   Updated: 2018/10/25 21:49:29 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_info	*create_info(char *path)
{
	t_info		*info;
	struct stat	struct_stat;

	if (stat(path, &struct_stat) == -1)
	{
		perror("stat");
		return (NULL);
	}
	if (!(info = (t_info *)malloc(sizeof(*info))))
		return (NULL);
	info->name = path;
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
	if (!(tab[0] = (char *)malloc(sizeof(char) * (nlen + 1))) ||
		!(tab[1] = (char *)malloc(sizeof(char) * (ft_strlen(name) - nlen))))
		return (NULL);
	while (nlen-- && (tab[0][i] = *name))
	{
		i++;
		name++;
	}
	name++;
	tab[0][i] = '\0';
	i = 0;
	while (*name && (tab[1][i] = *name))
	{
		i++;
		name++;
	}
	tab[1][i] = '\0';
	tab[2] = 0;
	return (tab);
}

char			**scut2(char *name)
{
	int		i;
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * 3)))
		return (NULL);
	if (!(tab[0] = (char *)malloc(sizeof(char) * 2)) ||
		!(tab[1] = (char *)malloc(sizeof(char) * (ft_strlen(name) + 1))))
		return (NULL);
	tab[0][0] = '.';
	tab[0][1] = '\0';
	i = 0;
	while (*name)
	{
		tab[1][i] = *name;
		name++;
		i++;
	}
	tab[1][i] = '\0';
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
		perror("opendir");
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
