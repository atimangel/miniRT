#include "minirt.h"

typedef struct s_plane
{
	t_vec3	*center;
	t_vec3	*normal;
	unsigned char red;
	unsigned char green;
	unsigned char blue;
}				t_plane;

void		ft_plane_touch(t_ray *r, t_pixel_unit *u)
{
	t_plane pl;
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
	free(pl.center);
}
