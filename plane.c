#include "minirt.h"

typedef struct s_plane
{
	t_vec3	*center;
	t_vec3	*normal;
	int		color;
}				t_plane;

void		ft_plane_touch(t_ray *r, int	*color)
{
	t_plane pl;
	double	t;
	t_vec3	*tmp;

	pl.center = ft_vec3(0.0, 0.0, -10.0);
	pl.normal = ft_vec3(-1.0, 1.0, -1.0);
	pl.color =  0x000090;
	if (ft_vec3_dot_product(*pl.normal, *r->d) == 0.0)
		;
	else
	{
		tmp = ft_vec3_remove(*pl.center, *r->e);
		t = ft_vec3_dot_product(*pl.normal, *tmp) / ft_vec3_dot_product(*pl.normal, *r->d);
		free(tmp);
		if (t > 0 && r->t > 0 && t < r->t)
		{
			r->t = t;
			*color = pl.color * (r->t_max - r->t) / r->t_max;
		}
	}
}
