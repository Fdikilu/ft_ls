/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 23:51:42 by fdikilu           #+#    #+#             */
/*   Updated: 2017/04/01 16:08:11 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tmp;
	char	*str;

	if (!(s1 && s2))
		return (NULL);
	i = 0;
	j = 0;
	tmp = (char *)s1;
	free((void *)s1);
	if (!(str = (char *)malloc(sizeof(*str)
		* (ft_strlen(tmp) + ft_strlen((char *)s2) + 1))))
		return (NULL);
	while (tmp[i] && (str[i] = tmp[i]))
		i++;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
