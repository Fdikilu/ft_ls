/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:36:40 by fdikilu           #+#    #+#             */
/*   Updated: 2016/11/29 22:17:31 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	int i;
	int j;
	int back_up_i;

	i = 0;
	j = 0;
	if (ft_strlen(to_find) == 0)
		return (str);
	while ((str[i] && i != (int)len) && to_find[j])
	{
		back_up_i = i;
		while ((str[i] == to_find[j]) && i != (int)len)
		{
			if (j == (ft_strlen(to_find) - 1))
				return (&str[i - j]);
			j++;
			i++;
		}
		i = back_up_i;
		i++;
		j = 0;
	}
	return (0);
}
