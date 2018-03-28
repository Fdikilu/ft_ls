/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 11:55:15 by fdikilu           #+#    #+#             */
/*   Updated: 2018/03/28 01:45:17 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_content_swap(t_list *l1, t_list *l2)
{
	void	*tmp;

	tmp = l2->content;
	l2->content = l1->content;
	l1->content = tmp;
}
