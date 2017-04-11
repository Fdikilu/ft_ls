
#include "ft_ls.h"

char	*ft_pwd(struct stat stat_pwd)
{
	struct passwd	*st_pwd;

	if (!(st_pwd = getpwuid(stat_pwd.st_uid)))
		perror("getpwuid");
	return (st_pwd->pw_name);
}
