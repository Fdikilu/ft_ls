
#include "ft_ls.h"

char	*ft_grp(struct stat stat_grp)
{
	struct group	*st_grp;

	if (!(st_grp = getgrgid(stat_grp.st_gid)))
		perror("getgrgid");
	return (st_grp->gr_name);
}
