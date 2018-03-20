/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 21:07:46 by fdikilu           #+#    #+#             */
/*   Updated: 2016/12/01 16:39:41 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int cpt;

	if (s)
	{
		cpt = 0;
		while (s[cpt])
		{
			ft_putchar_fd(s[cpt], fd);
			cpt += 1;
		}
		ft_putchar_fd('\n', fd);
	}
}
