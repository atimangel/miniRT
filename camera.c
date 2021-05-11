#include "minirt.h"

void	*ft_make_camera(char *line)
{
	t_camera	*cam;
	t_vec3		*tmp;

	cam = (t_camera *)malloc(sizeof(t_camera));
	if (!cam)
		printf("error\nmalloc error cam.c\n");
	line++;
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
	if (ft_vec3_len(cam->direction) != 1.0)
	{
		printf("warn\ncam direction vector is not normal\nbut it normalized\n");
		tmp = ft_vec3_normalize(cam->direction);
		ft_memcpy(&cam->direction, tmp, sizeof(t_vec3));
		free(tmp);
	}
	return (cam);
}
