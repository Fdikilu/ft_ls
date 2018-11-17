/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 23:52:38 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/14 16:01:11 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_char(int n)
{
	int				i;
	unsigned int	nb;

	i = 1 + ((n < 0) ? 1 : 0);
	nb = (n < 0) ? -n : n;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int					len_str;
	unsigned int		nb;
	char				*str;

	len_str = ft_nb_char(n);
	if (!(str = (char *)malloc(sizeof(*str) * (len_str + 1))))
		return (NULL);
	str[len_str] = '\0';
	nb = (n < 0) ? -n : n;
	while (len_str > 0)
	{
		len_str--;
		str[len_str] = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
