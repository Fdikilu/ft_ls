/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:57:09 by fdikilu           #+#    #+#             */
/*   Updated: 2018/03/31 16:42:52 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_info	*ft_info(struct dirent *struct_dir)
{
	t_info			*info;
	
	if (!(info = (t_info *)malloc(sizeof(*info))))
		return (NULL);
	if (stat(struct_dir->d_name, &info->s_st) == -1)
		perror("stat");
	info->name = struct_dir->d_name;
	info->time = ft_time(info->s_st);
	ft_mode(info->s_st, info->rights);
	info->pwd = ft_pwd(info->s_st);
	info->grp = ft_grp(info->s_st);
	return (info);
}

t_list	*ft_readdir(DIR *flux_dir)
{
	t_info			*info;
	t_list			*l_indir;
	struct dirent	*struct_dir;

	l_indir = NULL;
	while ((struct_dir = readdir(flux_dir)))
	{
		printf("ICI\n");
		if (!(info = ft_info(struct_dir)))
			printf("info marche pas\n");
		if (l_indir)
			ft_lstadd(&l_indir, ft_lstnew((t_info *)info, sizeof(*info)));
		else
			l_indir = ft_lstnew((t_info *)info, sizeof(*info));
	}
	return (l_indir);
}
