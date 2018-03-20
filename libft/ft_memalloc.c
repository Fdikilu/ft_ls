/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:10:49 by fdikilu           #+#    #+#             */
/*   Updated: 2016/12/01 14:36:02 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int	i;
	int	*zone;

	i = 0;
	zone = NULL;
	zone = malloc(sizeof(*zone) * size);
	if (zone == NULL)
		return (NULL);
	while (i < (int)size)
	{
		zone[i] = 0;
		i++;
	}
	return (zone);
}
