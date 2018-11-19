/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 00:30:26 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/19 21:54:11 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ls.h"

static int	norme(char *av, unsigned char *fl, t_ldir **l_d)
{
	struct stat	s_st;

	if (*fl & FLAG_ERR)
		return (1);
	else if (*av == '-' && (ft_strlen(av) > 1) && !(*fl & FLAG_TIR))
		init_flags(av, fl);
	else if ((lstat(av, &s_st) != -1) && S_ISDIR(s_st.st_mode))
	{
		if (!(*l_d = listdir(av, l_d, s_st)))
			return (1);
	}
	else
		return (0);
	return (1);
}

t_ldir		*ft_parse(char **av, unsigned char *flags)
{
	t_list		*l_file;
	t_ldir		*l_dir;
	int			here;
	struct stat	s_st;

	++av;
	l_dir = NULL;
	l_file = NULL;
	here = 1;
	while (*av)
	{
		(!(norme(*av, flags, &l_dir))) ? here = ft_isnotdir(*av, &l_file) : 0;
		if (*flags & FLAG_ERR)
			return (NULL);
		++av;
	}
	if ((!l_file && !l_dir) && here)
	{
		if (lstat(".", &s_st) == -1)
			perror("ft_ls");
		l_dir = listdir(".", &l_dir, s_st);
	}
	if (l_file)
		ft_print_file(l_file, flags);
	return (l_dir);
}
