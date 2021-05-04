#include "minirt.h"
#include <fcntl.h>
#include <string.h>

char	ft_isobj(char *line)
{
	if(ft_strnstr(line, "R ", 2))
		return (1);
	if(ft_strnstr(line, "A ", 2))
		return (2);
	if(ft_strnstr(line, "c ", 2))
		return (3);
	if(ft_strnstr(line, "l ", 2))
		return (4);
	if(ft_strnstr(line, "sp ", 3))
		return (5);
	if(ft_strnstr(line, "pl ", 3))
		return (6);
	if(ft_strnstr(line, "sq ", 3))
		return (7);
	if(ft_strnstr(line, "cy ", 3))
		return (8);
	if(ft_strnstr(line, "tr ", 3))
		return (9);
	return (0);
}

void	*ft_make_obj(char *line)
{
	if (ft_isobj(line) == 1)
		return(ft_make_resolution(line));
	if (ft_isobj(line) == 2)
		return(ft_make_ambient_reflection(line));
	if (ft_isobj(line) == 3)
		return(ft_make_camera(line));
	if (ft_isobj(line) == 4)
		return(ft_make_light(line));
	if (ft_isobj(line) == 5)
		return(ft_make_sphere(line));
	if (ft_isobj(line) == 6)
		return(ft_make_plane(line));
	if (ft_isobj(line) == 7)
		return(ft_make_square(line));
	if (ft_isobj(line) == 8)
		return(ft_make_cylinder(line));
	if (ft_isobj(line) == 9)
		return(ft_make_triangle(line));
}

t_list	*ft_parse_rt(char *file_name)
{
	char	*line;
	int	fd;
	t_list	*obj;
	char	flag;

	flag = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		printf("error\nfile open error\n");
	obj = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_isobj(line) == 1)
			flag += 1;
		if (ft_isobj(line) == 2)
			flag += 4;
		if (flag & 0x02 || flag & 0x08)
			printf("error\nyou can't make two R or A\n");
		if (ft_isobj(line))
			ft_lstadd_back(&obj, ft_lstnew(ft_make_obj(line)));
		printf("%s\n", line);	
	}
	close(fd);
	if (flag & 0x01 == 0)
		printf("error\nyou should set R");
	return (obj);
}
