/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 05:01:22 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/19 21:51:59 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ls.h"

struct group	*ft_grp(struct stat stat_grp)
{
	struct group	*st_grp;

	st_grp = NULL;
	if (!(st_grp = getgrgid(stat_grp.st_gid)))
		perror("getgrgid");
	return (st_grp);
}
