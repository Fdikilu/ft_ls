/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 03:17:34 by fdikilu           #+#    #+#             */
/*   Updated: 2016/08/15 08:21:16 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int		i;
	int		result;
	char	sign;

	i = 0;
	result = 0;
	while (str[i] == '\b' || str[i] == '\t' || str[i] == '\v'
	|| str[i] == ' ' || str[i] == '\n' || str[i] == '\f' || str[i] == '\r')
		i = i + 1;
	if (str[i] == '-')
	{
		sign = '-';
		i = i + 1;
	}
	else if (str[i] == '+')
		i = i + 1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (result * 10) + (str[i] - 48);
		i = i + 1;
	}
	if (sign == '-')
		return (result * (-1));
	else
		return (result);
}
