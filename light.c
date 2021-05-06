#include "minirt.h"

void	*ft_make_light(char *line)
{
	t_light	*li;

	li = (t_light *)malloc(sizeof(t_light));
	if (!li)
		printf("error\nmalloc error light.c");
	line++;
	line = ft_pass_space(line);
	line = ft_read_vec3(line, li->point);
	line = ft_pass_space(line);
	line = ft_read_float(line, &li->ratio, 0);
	line = ft_pass_space(line);
	line = ft_read_char(line, &li->red, 1);
	line = ft_read_char(line, &li->green, 1);
	line = ft_read_char(line, &li->blue, 0);
	line = ft_pass_space(line);
	if (*line != '\0')
		printf("error\nlight parsing error string is not end with null character\n");
	if (li->ratio < 0.0 || li->ratio > 1.0)
		printf("error\nlight bright ratio is not in range 0.0 ~ 1.0 ,%f\n", li->ratio);
	return (li);
}

void	ft_light_max(t_pixel_unit *u)
{
	if (u->p_r > 255)
		u->p_r = 255;
	if (u->p_g > 255)
		u->p_g = 255;
	if (u->p_b > 255)
		u->p_b = 255;
}
