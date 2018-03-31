/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 01:07:45 by fdikilu           #+#    #+#             */
/*   Updated: 2018/03/28 15:22:30 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = NULL;
	lst = (t_list *)malloc(sizeof(*lst));
	if (lst == NULL)
		return (lst);
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
		lst->next = NULL;
	}
	else
	{
		lst->content = (void *)malloc(content_size);
		if (lst->content == NULL)
			return (NULL);
		ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
		lst->next = NULL;
	}
	return (lst);
}
