/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 04:48:56 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/19 21:52:47 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "ft_ls.h"

char	*ft_time(struct stat st_t)
{
	char	*time;

	if (!(time = ft_strchr(ctime(&st_t.st_mtime), ' ')))
		return (NULL);
	return (ft_strsub(time, 1, 12));
}
