/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 00:30:26 by fdikilu           #+#    #+#             */
/*   Updated: 2018/03/16 05:23:00 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_parse(char *str, unsigned char *flags)
{
	int				i;

	i = 1;
	while (str[i])
	{
		if (str[i] == 'l')
			*flags |= FLAG_L;
		else if (str[i] == 'R')
			*flags |= FLAG_UPR;
		else if (str[i] == 'a')
			*flags |= FLAG_A;
		else if (str[i] == 'r')
			*flags |= FLAG_R;
		else if (str[i] == 't')
			*flags |= FLAG_T;
		else
		{
			*flags |= FLAG_ERR;
			return ;
		}
		i++;
	}
}

void	ft_ls(char **av, unsigned char *flags)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (*flags & FLAG_ERR)
		{
			printf("usage: [-lRart] [file ...]");
			return ;
		}
		else if (av[i][0] == '-')
			ft_parse(av[i], flags);
		else
			ft_dols(av[i], flags);
		i++;
	}
}
