/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:55:47 by fdikilu           #+#    #+#             */
/*   Updated: 2018/10/30 23:10:35 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define FLAGS "lRart"

# define NO_FLAG 0
# define FLAG_L 1
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
	char			*buf;
	char			name[5096];
	char			*path;
	struct stat		s_st;
	char			*time;
	char			rights[11];
	struct passwd	*pwd;
	struct group	*grp;
}					t_info;

typedef struct		s_ldir
{
	char			*name;
	DIR				*f_dir;
	struct s_ldir	*next;
}					t_ldir;

void				init_flags(char *s, unsigned char *flags);
char				*ft_time(struct stat st_t);
struct group		*ft_grp(struct stat stat_grp);
struct passwd		*ft_pwd(struct stat stat_pwd);
void				ft_mode(struct stat stat_m, char rights[11]);
t_ldir				*ft_parse(int ac, char **av, unsigned char *flags);
t_ldir				*listdir(char *s, DIR *fdir, t_ldir **l_dir);
t_list				*ft_readdir(DIR *flux_dir, char *ndir);
void				ft_content_swap(t_list *l1, t_list *l2);
char				*concat(char *ndir, char *nfile);
void				ft_sort(t_list *l_indir, unsigned char flags);
int					ft_timecmp(struct stat st1, struct stat st2);
void				ft_isnotdir(char *name, t_list **lfile);
void				ft_print_file(t_list *l_file, unsigned char *flags);
void				ft_ls(t_ldir *l_dir, unsigned char fl);

#endif
