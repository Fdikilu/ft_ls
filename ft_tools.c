/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:32:18 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/18 14:36:49 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*concat(char *ndir, char *nfile)
{
	char	*path;

	if (!(path = ft_strnew(ft_strlen(ndir) + ft_strlen(nfile) + 1)))
		return (NULL);
	ft_strcpy(path, ndir);
	ft_strcat(path, "/");
	ft_strcat(path, nfile);
	return (path);
}

char	**scut2(char *name)
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
