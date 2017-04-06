/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 22:26:11 by fdikilu           #+#    #+#             */
/*   Updated: 2017/04/05 11:45:57 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// probleme des . .. en sortie quand ya plusieur arg

t_list	*test(char *str)
{
	t_list		*l_dir;

	l_dir = read_dir(str);
	ft_ascii_sort(l_dir);
	return (l_dir);
}

int main(int argc, char **argv)
{
	int			i;
	t_list		*tmp;
	t_list		*l_tab[argc - 1];

	i = 1;
	while (i < argc)
	{
		l_tab[i - 1] = test(argv[i]);
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		tmp = l_tab[i];
		printf("\n\n-------%s------ :\n", argv[i + 1]);
		while (tmp)
		{
			printf("%s\n", (char *)tmp->content);
			tmp = tmp->next;
		}
		i++;
	}
	return (0);
}
