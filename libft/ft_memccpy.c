/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 22:29:00 by fdikilu           #+#    #+#             */
/*   Updated: 2016/12/12 15:39:06 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*sou;
	char		*des;

	sou = (char *)src;
	des = (char *)dst;
	while (n--)
	{
		*(des++) = *sou;
		if (*(sou++) == (char)c)
			return (des);
	}
	return (NULL);
}
