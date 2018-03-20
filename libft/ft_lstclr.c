/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:43:35 by fdikilu           #+#    #+#             */
/*   Updated: 2017/02/16 12:48:40 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclr(t_list **begin_list)
{
	t_list	*elem;

	elem = *begin_list;
	while (elem != NULL)
	{
		elem = (*begin_list)->next;
		free((*begin_list)->content);
		free(*begin_list);
		*begin_list = elem;
	}
	begin_list = NULL;
}
