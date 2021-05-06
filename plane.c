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
		printf("error\nstring is not end null character plane.c");
	if (ft_vec3_len(pl->normal) != 1.0)
	{
		normal = ft_vec3_normalize(pl->normal);
		ft_memcpy(&pl->normal, normal, sizeof(t_vec3));
		free(normal);
	}
	return (pl);
}

void		ft_plane_touch(t_ray *r, t_pixel_unit *u)
{
/*	t_plane pl;
	double	t;
	t_vec3	*tmp;
	double	len;

	pl.center = ft_vec3(0.0, 0.0, -10.0);
	pl.normal = ft_vec3(0.0, 0.0, 1.0);
	pl.red =  0x00;
	pl.green = 0x90;
	pl.blue = 0x90;
	if (ft_vec3_dot_product(*pl.normal, *r->d) != 0.0)
	{
		tmp = ft_vec3_remove(*pl.center, *r->e);
		t = ft_vec3_dot_product(*pl.normal, *tmp) / ft_vec3_dot_product(*pl.normal, *r->d);
		free(tmp);
		if (t > 0 && ((r->t > 0 && t < r->t) || r->t <= 0))
		{
			tmp = ft_vec3_remove(*r->e, *r->d);
			len = t * ft_vec3_len(*tmp);
			free(tmp);
			r->t = t;
			u->o_r = pl.red;
			u->o_g = pl.green;
			u->o_b = pl.blue;
			if (u->o_n != 0)
				free(u->o_n);
			if (ft_vec3_dot_product(*pl.normal, *r->d) < 0)
				u->o_n = pl.normal;
			else
				u->o_n = ft_vec3_scale(*pl.normal, -1.0);
			printf("pl.normal ");
			ft_putvec(*pl.normal);
			printf("u->o_n ");
			ft_putvec(*u->o_n);
		}
	}
	if (u->o_n != pl.normal)
		free(pl.normal);
	free(pl.center);*/
}
