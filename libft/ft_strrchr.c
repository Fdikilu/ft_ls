/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:57:56 by fdikilu           #+#    #+#             */
/*   Updated: 2016/12/14 18:05:12 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	c2;
	char			*tmp;

	tmp = NULL;
	c2 = (unsigned char)c;
	while (*s)
	{
		if (*s == c2)
			tmp = (char *)s;
		s++;
	}
	if (*s == c2)
		return ((char *)s);
	return (tmp);
}
