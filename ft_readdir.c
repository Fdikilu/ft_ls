/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:57:09 by fdikilu           #+#    #+#             */
/*   Updated: 2018/03/27 20:15:59 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*ft_readdir(DIR *flux_dir, t_list *l_dir)
{
	struct dirent	*struct_dir;

	while ((struct_dir = readdir(flux_dir)))
		if (l_dir)
			ft_lstadd(&l_dir, ft_lstnew((char *)struct_dir->d_name, 256));
		else
			l_dir = ft_lstnew((char *)struct_dir->d_name, 256);
	if (closedir(flux_dir))
		perror("closedir");
	return (l_dir);
}
