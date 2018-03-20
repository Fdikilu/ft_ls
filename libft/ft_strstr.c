/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 04:16:44 by fdikilu           #+#    #+#             */
/*   Updated: 2016/08/18 01:24:46 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int back_up_i;

	i = 0;
	j = 0;
	if (ft_strlen(to_find) == 0)
		return (str);
	while (str[i] && to_find[j])
	{
		back_up_i = i;
		while (str[i] == to_find[j])
		{
			if (j == (ft_strlen(to_find) - 1))
				return (&str[i - j]);
			j++;
			i++;
		}
		i = back_up_i;
		i = i + 1;
		j = 0;
	}
	return (0);
}
