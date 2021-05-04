#include "minirt.h"

void	*ft_make_camera(char *line)
{
	t_camera	*cam;

	cam = (t_camera *)malloc(sizeof(t_camera));
	if (!cam)
		printf("error\nmalloc error cam.c\n");
	line++;
	cam->id = c;
	line = ft_pass_space(line);
	line = ft_read_vec3(line, cam->camera);
	line = ft_pass_space(line);
	line = ft_read_vec3(line, cam->direction);
	line = ft_pass_space(line);
	line = ft_read_float(line, &cam->fov, 0);
	line = ft_pass_space(line);
	if (*line != '\0')
		printf("error\ncam parsing string read error\n");
	if (cam->fov < 0 || cam->fov > 180)
		printf("error\ncamera fob over or under value\n");
	return (cam);
}
