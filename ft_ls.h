/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:55:47 by fdikilu           #+#    #+#             */
/*   Updated: 2018/11/17 19:17:17 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define FLAGS "lRart"

# define C_NONE		"\033[0m"
# define C_RED		"\033[31m"
# define C_GREEN	"\033[32m"
# define C_YELLOW	"\033[33m"
# define C_BLUE		"\033[34m"
# define C_MAGENTA	"\033[35m"
# define C_CYAN		"\033[36m"
# define C_ORANGE	"\033[91m"

# define NO_FLAG 0
# define FLAG_L 1
# define FLAG_R 2
# define FLAG_A 4
# define FLAG_UPR 8
# define FLAG_T 16
# define FLAG_UPG 32
# define FLAG_TIR 64
# define FLAG_ERR 128

# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
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
	char			name[2048];
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
	struct stat		s_st;
	struct s_ldir	*next;
}					t_ldir;

void				select_color(char *rights);
char				*todisp(char *info, char *str, int size);
char				*todisp2(char *info, char *str, int size);
char				*concat(char *ndir, char *nfile);
void				rec_free(t_ldir *rec);
void				tab_free(char **tab);
void				lindir_free(t_list *l_indir);
void				init_flags(char *s, unsigned char *flags);
void				ft_blocks(t_list *l_indir, unsigned char flags);
void				l_sizecolonne(t_list *l_indir, int size[5]);
void				ft_loption(t_info *info, unsigned char flags, int size[5]);
char				*ft_time(struct stat st_t);
struct group		*ft_grp(struct stat stat_grp);
struct passwd		*ft_pwd(struct stat stat_pwd);
void				ft_mode(struct stat stat_m, char rights[11]);
t_ldir				*ft_parse(char **av, unsigned char *flags);
t_ldir				*listdir(char *s, t_ldir **l_dir, struct stat s_st);
t_list				*ft_readdir(t_ldir *dir, \
	DIR **flux_dir, unsigned char flags);
void				ft_content_swap(t_list *l1, t_list *l2);
void				ft_sort(t_list *l_indir, unsigned char flags);
int					ft_timecmp(struct stat st1, struct stat st2);
int					ft_isnotdir(char *name, t_list **lfile);
void				ft_print_file(t_list *l_file, unsigned char *flags);
void				ft_display(t_info *info, unsigned char flags, int size[5]);
void				ft_ls(t_ldir *l_dir, unsigned char fl, int frst);

#endif
