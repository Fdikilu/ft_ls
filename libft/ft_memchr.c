/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 22:51:34 by fdikilu           #+#    #+#             */
/*   Updated: 2016/12/14 17:30:40 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c2;

	c2 = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == c2)
			return (str);
		str++;
	}
	return (NULL);
}
