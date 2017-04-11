
#include "ft_ls.h"

char	*ft_time(struct stat st_t)
{
	char	*time;

	if (!(time = ft_strchr(ctime(&st_t.st_mtime), ' ')))
		return (NULL);
	return (ft_strsub(time, 1, 12));
}
