/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 22:31:17 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/10 23:28:39 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	norme(t_info *info, char *nlink, char *pwd, int size[5])
{
	ft_putstr(info->rights);
	ft_putstr("  ");
	ft_putstr(todisp(ft_itoa(info->s_st.st_nlink), nlink, size[0]));
	ft_putchar(' ');
	ft_putstr(todisp2(info->pwd->pw_name, pwd, size[1]));
	ft_putstr("  ");
}

static void	norme2(t_info *info, unsigned char flags)
{
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

void		ft_loption(t_info *info, unsigned char flags, int size[5])
{
	char	nlink[size[0] + 1];
	char	pwd[size[1] + 1];
	char	grp[size[2] + 1];
	char	major[size[3] + 1];
	char	minsiz[size[4] + 1];

	norme(info, nlink, pwd, size);
	ft_putstr(todisp2(info->grp->gr_name, grp, size[2]));
	(size[3] > 0) ? ft_putstr("   ") : ft_putstr("  ");
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
	norme2(info, flags);
}
