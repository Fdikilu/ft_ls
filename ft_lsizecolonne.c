/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsizecolonne.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 22:22:34 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/10 22:22:40 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	nb_digit(int n)
{
	int		len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

static void	value_size(t_info *info, int size[5])
{
	int		i;

	i = 0;
	i = nb_digit(info->s_st.st_nlink);
	size[0] = (size[0] < i) ? i : size[0];
	i = ft_strlen(info->pwd->pw_name);
	size[1] = (size[1] < i) ? i : size[1];
	i = ft_strlen(info->grp->gr_name);
	size[2] = (size[2] < i) ? i : size[2];
	if (info->rights[0] == 'c' || info->rights[0] == 'b')
	{
		i = nb_digit(major(info->s_st.st_rdev));
		size[3] = (size[3] < i) ? i : size[3];
	}
	if (info->rights[0] == 'c' || info->rights[0] == 'b')
	{
		i = nb_digit(minor(info->s_st.st_rdev));
		size[4] = (size[4] < i) ? i : size[4];
	}
	else
	{
		i = nb_digit(info->s_st.st_size);
		size[4] = (size[4] < i) ? i : size[4];
	}
}

void		l_sizecolonne(t_list *l_indir, int size[5])
{
	int		i;

	i = 5;
	while (i--)
		size[i] = 0;
	while (l_indir)
	{
		value_size(l_indir->content, size);
		l_indir = l_indir->next;
	}
}
