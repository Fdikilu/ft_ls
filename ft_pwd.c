/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 05:00:27 by fdikilu           #+#    #+#             */
/*   Updated: 2018/03/28 05:01:19 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct passwd	*ft_pwd(struct stat stat_pwd)
{
	struct passwd	*st_pwd;

	st_pwd = NULL;
	if (!(st_pwd = getpwuid(stat_pwd.st_uid)))
		perror("getpwuid");
	return (st_pwd);
}
