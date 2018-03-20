/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 12:43:21 by fdikilu           #+#    #+#             */
/*   Updated: 2016/12/17 19:15:41 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	destlen;

	destlen = (size_t)ft_strlen(dest);
	i = 0;
	while (src[i] && destlen + i < size - 1 && size > 0)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	if (size < destlen + i)
		return (size + ft_strlen((char *)src));
	return (destlen + ft_strlen((char *)src));
}
