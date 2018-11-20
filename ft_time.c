/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 04:48:56 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/20 22:19:24 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "ft_ls.h"

char	*ft_time(struct stat st_t)
{
	char	year[5];
	char	*tim;

	tim = ft_strchr(ctime(&st_t.st_mtime), ' ');
	ft_strcpy(year, ft_strrchr(tim, ' '));
	year[0] = year[1];
	year[1] = year[2];
	year[2] = year[3];
	year[3] = year[4];
	year[4] = '\0';
	if (!(tim = ft_strsub(tim, 1, 12)))
		return (NULL);
	if (((time(NULL) - st_t.st_mtime) > 15778800)
		|| ((time(NULL) - st_t.st_mtime) < 0))
	{
		tim[11] = year[3];
		tim[10] = year[2];
		tim[9] = year[1];
		tim[8] = year[0];
		tim[7] = ' ';
	}
	return (tim);
}
