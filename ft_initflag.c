/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:39:45 by fdikilu           #+#    #+#             */
/*   Updated: 2018/10/26 17:42:03 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		flags_on(unsigned char *tmp, int c)
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

void			init_flags(char *s, unsigned char *flags)
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
