/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnotdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:16:37 by fdikilu           #+#    #+#             */
/*   Updated: 2018/03/28 11:39:25 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_info	*create_info(struct dirent *struct_dir)
{
	t_info		*info;
	struct stat	struct_stat;

	if (!(info = (t_info *)malloc(sizeof(*info))))
		return (NULL);
	if (stat(struct_dir->d_name, &struct_stat) == -1)
	{
		perror("stat");
		free((void *)info);
		return (NULL);
	}
	info->name = struct_dir->d_name;
	info->s_st = struct_stat;
	ft_mode(struct_stat, info->rights);
	info->pwd = ft_pwd(struct_stat);
	info->grp = ft_grp(struct_stat);
	info->time = ft_time(struct_stat);
	return (info);
}

void	ft_isnotdir(char *name, t_list **l_file, unsigned char *flags)
{
	struct dirent	*struct_dir;
	DIR				*flux_dir;
	t_info			*tmp;

	tmp = NULL;
	(void)flags;
	if (!(flux_dir = opendir(".")))
		perror("opendir");
	while ((struct_dir = readdir(flux_dir)))
		if (ft_strcmp(struct_dir->d_name, name) == 0)
		{
			if (!(tmp = create_info(struct_dir)))
				return ;
			if (!(*l_file))
			{
				*l_file = ft_lstnew((t_info *)tmp, sizeof(*tmp));
				return ;
			}
			else
			{
				ft_lstadd(l_file, ft_lstnew((t_info *)tmp, sizeof(*tmp)));
				return ;
			}
		}
}

void	ft_print_file(t_list *l_file, unsigned char *flags)
{
	t_info	*tmp;

	if (*flags & FLAG_R && !(*flags & FLAG_T))
		ft_ascii_sortr(l_file);
	else if (*flags & FLAG_T && !(*flags & FLAG_R))
		ft_ascii_sort_time(l_file);
	else if (*flags & FLAG_T && *flags & FLAG_R)
		ft_ascii_sort_timer(l_file);
	else
		ft_ascii_sort(l_file);
	if (*flags & FLAG_L)
	{
		while (l_file)
		{
			tmp = l_file->content;
			printf("%s %d %s %s", tmp->rights, tmp->s_st.st_nlink, tmp->pwd->pw_name, tmp->grp->gr_name);
			printf(" %lld %s %s\n", tmp->s_st.st_size, tmp->time, tmp->name);
			l_file = l_file->next;
		}
	}
	else
	{
		while (l_file->next)
		{
			printf("%s\t", ((t_info *)l_file->content)->name);
			l_file = l_file->next;
		}
		printf("%s\n", ((t_info *)l_file->content)->name);
	}
}
