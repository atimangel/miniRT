#include "minirt.h"

void		*ft_make_plane(char *line)
{
	t_plane	*pl;
	t_vec3	*normal;

	pl = (t_plane *)malloc(sizeof(t_plane));
	if (!pl)
		printf("error\nmalloc error plane.c");
	line += 2;
	line = ft_pass_space(line);
	line = ft_read_vec3(line, pl->center);
	line = ft_pass_space(line);
	line = ft_read_vec3(line, pl->normal);
	line = ft_pass_space(line);
	line = ft_read_char(line, &pl->red, 1);
	line = ft_read_char(line, &pl->green, 1);
	line = ft_read_char(line, &pl->blue, 0);
	line = ft_pass_space(line);
	if (*line != '\0')
		printf("error\nstring is not end null character plane.c\n%s", line);
	if (ft_vec3_len(pl->normal) != 1.0)
	{
		normal = ft_vec3_normalize(pl->normal);
		ft_memcpy(&pl->normal, normal, sizeof(t_vec3));
		free(normal);
	}
	return (pl);
}

double		ft_plane_touch(t_ray *r, t_pixel_unit *u, void *obj, char flag)
{
	t_plane *pl;
	double	t;
	t_vec3	*tmp;

	pl = obj;
	if (ft_vec3_dot_product(pl->normal, *r->d) != 0.0)
	{
		tmp = ft_vec3_remove(pl->center, r->e);
		t = ft_vec3_dot_product(pl->normal, *tmp) / ft_vec3_dot_product(pl->normal, *r->d);
		free(tmp);
		if (t > 0 && ((r->t > 0 && t < r->t) || r->t <= 0))
		{
			if (flag == 1)
				return (t);
			u->o_r = pl->red;
			u->o_g = pl->green;
			u->o_b = pl->blue;
			if (u->o_n != 0)
				free(u->o_n);
			if (ft_vec3_dot_product(pl->normal, *r->d) < 0)
				u->o_n = ft_vec3(pl->normal[0], pl->normal[1], pl->normal[2]);
			else
				u->o_n = ft_vec3_scale(pl->normal, -1.0);
			return (t);
		}
	}
	return (-1);
}
