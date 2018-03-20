/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 02:34:30 by fdikilu           #+#    #+#             */
/*   Updated: 2018/03/19 21:32:06 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_list			*l_dir;
	unsigned char	flags;

	(void)av;
	if (ac < 1)
		return (0);
	if (!(l_dir = ft_parse(av, &flags)))
		printf("liste non creer\n");
	ft_putstr("flags :");
	ft_putnbr((int)flags);
	ft_putchar('\n');
	if (l_dir)
	{
		printf("%s\n", (char *)l_dir->content);
		l_dir = l_dir->next;
	}
	return (0);
}
