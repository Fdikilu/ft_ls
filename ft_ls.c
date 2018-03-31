/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:04:09 by fdikilu           #+#    #+#             */
/*   Updated: 2018/03/31 14:14:32 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_node	*create_node(char *name, DIR *f_dir)
{
	t_node	*node;

	if (!(node = (t_node*)malloc(sizeof(*node))))
		return (NULL);
	node->name = name;
	node->f_dir = f_dir;
	return (node);
}

static t_bt		*ls_create(char *name, DIR *)
{
	t_bt	*f_bt;
	
	ft
}

static int		ls_print()
{}

static int		ls_free()
{}

void	ft_ls(char *name, DIR *fdir, unsigned char flags)
{

	ls_create();
	ls_print();
	ls_free();
	if (flags & FLAG_UPR)
		ft_ls();
}

int	main(void)
{
	DIR	*test;
	t_bt	*bt_dir;
	t_list	*list;
	t_node	*node;

	test = NULL;
	node = create_node("test", test);
	list = ft_lstnew(NULL,0);
	bt_dir = ft_btnew(node, sizeof(*node));
	free((void *)node);
	printf("node: %zu\n", sizeof(*node));
	printf("node: %zu\n", sizeof(*list));
	printf("node: %zu\n", sizeof(*bt_dir));
	printf("name : %s\n", ((t_node *)bt_dir->data)->name);
	return (0);
}
