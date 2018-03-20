/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 00:30:26 by fdikilu           #+#    #+#             */
/*   Updated: 2018/03/20 05:51:23 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void flags_on(unsigned char *tmp, int c)
{	
	if (c == 'l')
		*tmp |= FLAG_L;
	else if (c == 'R')
		*tmp |= FLAG_UPR;
	else if (c == 'a')
		*tmp |= FLAG_A;
	else if (c == 'r')
		*tmp |= FLAG_R;
	else if (c == 't')
		*tmp |= FLAG_T;
	else if (c == '-' && (*tmp == NO_FLAG))
		return ;
	else
	{
		*tmp |= FLAG_ERR;
		*tmp &= FLAG_ERR;
		return ;
	}
}

static void	init_flags(char *s, unsigned char *flags)
{
	unsigned char	tmp;

	++s;
	if (*s == '\0')
	{
		*flags |= FLAG_ERR;
		return ;
	}
	tmp = NO_FLAG;
	while (*s)
	{
		flags_on(&tmp, *s);
		++s;
	}
	*flags |= tmp;
}
/*
static t_list	*parse_f(char *s)
{
	t_list	*l_dir;

	return (l_dir);
}*/

t_list	*ft_parse(char **av, unsigned char *flags)
{
	t_list	*l_dir;

	++av;
	l_dir = NULL;
	while (*av)
	{
		if (*flags & FLAG_ERR || (**av == '-' && ft_strlen(*av) == 1))
		{
			printf("usage: [-lRart] [file ...]\n");
			return (NULL);
		}
		else if (**av == '-')
			init_flags(*av, flags);
		else
		{
		//	parse_f();
		}
		++av;
	}
	return (l_dir);
}
