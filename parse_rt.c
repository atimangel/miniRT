#include "minirt.h"
#include <fcntl.h>
#include <string.h>

char	ft_isobj(char *line)
{
	if(ft_strnstr(line, "A ", 2))
		return (1);
	if(ft_strnstr(line, "C ", 2))
		return (2);
	if(ft_strnstr(line, "L ", 2))
		return (3);
	if(ft_strnstr(line, "sp ", 3))
		return (4);
	if(ft_strnstr(line, "pl ", 3))
		return (5);
	if(ft_strnstr(line, "cy ", 3))
		return (6);
	return (0);
}

void	*ft_make_obj(char *line)
{
	if (ft_isobj(line) == 1)
		return(ft_make_ambient_reflection(line));
	if (ft_isobj(line) == 2)
		return(ft_make_camera(line));
	if (ft_isobj(line) == 3)
		return(ft_make_light(line));
	if (ft_isobj(line) == 4)
		return(ft_make_sphere(line));
	if (ft_isobj(line) == 5)
		return(ft_make_plane(line));
	if (ft_isobj(line) == 6)
		return(ft_make_cylinder(line));
	return (0);
}

char	capital_letter(char flag, char id)
{
	if (id == 1)
	{
		if (flag & 0b00000001)
			exit(0);
		else
			return (1);
	}
	else if (id == 2)
	{
		if (flag & 0b00000010)
			exit(0);
		else
			return(2);
	}
	else if (id == 3)
	{
		if (flag & 0b00000100)
			exit(0);
		else
			return (4);
	}
	return (0);
}

t_list	*ft_parse_rt(char *file_name)
{
	char	*line;
	int		fd;
	t_list	*obj;
	char	flag;
	t_list	*last;

	flag = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		printf("error\nfile open error\n");
		exit (0);
	}
	obj = 0;
	while (get_next_line(fd, &line) > 0)
	{
		flag += capital_letter(flag, ft_isobj(line));
		if (ft_isobj(line))
		{
			ft_lstadd_back(&obj, ft_lstnew(ft_make_obj(line)));
			ft_lstlast(obj)->id = ft_isobj(line);
		}
		printf("tmp| %s\n", line);
		free(line);
	}
	free(line);
	if (flag != 0b00000111)
		printf("error%d\n");
	close(fd);
	return (obj);
}
