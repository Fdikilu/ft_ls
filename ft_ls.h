/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:55:47 by fdikilu           #+#    #+#             */
/*   Updated: 2018/03/16 10:04:16 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define FLAGS "lRart"

# define NO_FLAG 0
# define FLAG_l 1
# define FLAG_R 2
# define FLAG_A 4
# define FLAG_UPR 8
# define FLAG_T 16
# define FLAG_ERR 128

# include <sys/types.h>
# include <sys/stat.h>
# include <grp.h>
# include <pwd.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include <dirent.h>
# include "libft/libft.h"

typedef struct		s_info
{
	char			right[11];
	struct stat		s_stat;
	struct passwd	pwd;
	struct group	grp;
	char			*time;
	struct dirent	dir;
}					t_info;

typedef struct		s_bt
{
	struct s_bt		*parent;
	struct s_bt		*left;
	struct s_bt		*right;
	void			*data;
	size_t			data_size;
}					t_bt;

void				ft_ls(unsigned char flags);
t_list				*ft_readdir(char *name);
void				ft_content_swap(t_list *l1, t_list *l2);
void				ft_ascii_sort(t_list *l_dir);

#endif
