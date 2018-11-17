/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:27:33 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/17 22:52:42 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	select_color(char *rights)
{
	if (rights[0] == 'd')
		ft_putstr(C_BLUE);
	else if (rights[0] == 'c')
		ft_putstr(C_YELLOW);
	else if (rights[0] == 'b')
		ft_putstr(C_MAGENTA);
	else if (rights[0] == 'p')
		ft_putstr(C_GREEN);
	else if (rights[0] == 'l')
		ft_putstr(C_CYAN);
	else if (rights[0] == 's')
		ft_putstr(C_ORANGE);
	else if (rights[0] == '-')
		if (rights[3] == 'x' || rights[6] == 'x' || rights[9] == 'x')
			ft_putstr(C_RED);
}

char	*todisp(char *info, char *str, int size)
{
	int		leninfo;

	leninfo = ft_strlen(info);
	str[size] = '\0';
	while (size-- && leninfo--)
		str[size] = info[leninfo];
	free((void *)info);
	if (size < 0)
		return (str);
	else if (size == 0)
		str[0] = ' ';
	size++;
	while (size--)
		str[size] = ' ';
	return (str);
}

char	*todisp2(char *info, char *str, int size)
{
	int		i;

	i = 0;
	while (info[i])
	{
		str[i] = info[i];
		i++;
	}
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_display(t_info *info, unsigned char flags, int size[5])
{
	if (info->name[0] == '.' && !(flags & FLAG_A))
	{
		(info->rights[0] == 'l') ? free((void *)info->buf) : 0;
		free((void *)info->time);
		free((void *)info->path);
		return ;
	}
	if (flags & FLAG_L)
		ft_loption(info, flags, size);
	else if (flags & FLAG_UPG)
	{
		select_color(info->rights);
		ft_putstr(info->name);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr(info->name);
		ft_putchar('\n');
	}
	ft_putstr(C_NONE);
	(info->rights[0] == 'l') ? free((void *)info->buf) : 0;
	free((void *)info->time);
	free((void *)info->path);
}
