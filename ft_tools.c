/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:32:18 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/21 00:21:11 by fdikilu          ###   ########.fr       */
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
	if ((!(tab[0] = ft_strnew(1))))
	{
		free((void *)tab);
		return (NULL);
	}
	if (!(tab[1] = ft_strnew(ft_strlen(name))))
	{
		ft_strdel(&tab[0]);
		free((void *)tab);
		return (NULL);
	}
	tab[0][0] = '.';
	ft_strcpy(tab[1], name);
	tab[2] = 0;
	return (tab);
}

char	*todisp(char *info, char *str, int size)
{
	int		leninfo;

	if (!info)
		return (NULL);
	leninfo = ft_strlen(info);
	str[size] = '\0';
	while (size-- && leninfo--)
		str[size] = info[leninfo];
	free((void *)info);
	if (size < 0)
		return (str);
	else if (size == 0)
		str[0] = ' ';
	size++;
	while (size--)
		str[size] = ' ';
	return (str);
}

char	*todisp2(char *info, char *str, int size)
{
	int		i;

	if (!info || !size)
		return (NULL);
	i = 0;
	while (info[i])
	{
		str[i] = info[i];
		i++;
	}
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}
