/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 19:42:06 by fdikilu           #+#    #+#             */
/*   Updated: 2016/11/29 22:27:06 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int		cpt;
	char	*test;

	cpt = 0;
	test = s;
	while (cpt < (int)n)
	{
		test[cpt] = c;
		cpt++;
	}
	return (s);
}
