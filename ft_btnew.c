/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 02:36:48 by fdikilu           #+#    #+#             */
/*   Updated: 2018/03/31 12:21:37 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bt	*ft_btnew(void const *data, size_t data_size)
{
	t_bt	*bt;
	bt = NULL;
	if (!(bt = (t_bt *)malloc((sizeof(*bt)))))
		return (NULL);
	if (!data)
	{
		bt->data = NULL;
		bt->data_size = 0;
		bt->l = NULL;
		bt->r = NULL;
	}
	else
	{
		if (!(bt->data = (void *)malloc(data_size)))
			return (NULL);
		ft_memcpy(bt->data, data, data_size);
		bt->data_size = data_size;
		bt->l = NULL;
		bt->r = NULL;
	}
	return (bt);
}
