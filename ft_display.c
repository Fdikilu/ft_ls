/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:27:33 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/09 20:32:16 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	select_color(char *rights)
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

static char	*todisp(char *info, char *str, int size)
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

static char	*todisp2(char *info, char *str, int size)
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

static void	l_op(t_info *info, unsigned char flags, int size[5])
{
	char	nlink[size[0] + 1];
	char	pwd[size[1] + 1];
	char	grp[size[2] + 1];
	char	major[size[3] + 1];
	char	minsiz[size[4] + 1];

	ft_putstr(info->rights);
	ft_putstr("  ");
	ft_putstr(todisp(ft_itoa(info->s_st.st_nlink), nlink, size[0]));
	ft_putchar(' ');
	ft_putstr(todisp2(info->pwd->pw_name, pwd, size[1]));
	ft_putstr("  ");
	ft_putstr(todisp2(info->grp->gr_name, grp, size[2]));
	ft_putstr("  ");
	(size[3] > 0) ? ft_putchar(' ') : 0;
	if (info->rights[0] == 'c' || info->rights[0] == 'b')
	{
		ft_putstr(todisp(ft_itoa(major(info->s_st.st_rdev)), major, size[3]));
		ft_putchar(',');
		ft_putstr(todisp(ft_itoa(minor(info->s_st.st_rdev)), minsiz, size[4]));
	}
	else
	{
		if (size[3])
		{
			ft_putstr(todisp(ft_strnew(0), major, size[3]));
			ft_putchar(' ');
		}
		ft_putstr(todisp(ft_itoa(info->s_st.st_size), minsiz, size[4]));
	}
	ft_putchar(' ');
	ft_putstr(info->time);
	ft_putchar(' ');
	if (flags & FLAG_UPG)
		select_color(info->rights);
	ft_putstr(info->name);
	if (info->rights[0] == 'l')
	{
		ft_putstr(C_NONE);
		ft_putstr(" -> ");
		ft_putstr(info->buf);
	}
	ft_putchar('\n');
}

void		ft_display(t_info *info, unsigned char flags, int size[5])
{
	if (info->name[0] == '.' && !(flags & FLAG_A))
		return ;
	if (flags & FLAG_L)
		l_op(info, flags, size);
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
	free((void *)info->path);
}
