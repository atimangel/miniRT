#include "minirt.h"
#include <fcntl.h>
#include <string.h>

int	ft_parse_rt(char *file_name, void **object_list)
{
	char	*line;
	int	fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);	
	}
}
