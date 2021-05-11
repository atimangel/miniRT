#include "minirt.h"

void	ft_reflection(t_ray r, t_pixel_unit *u, t_list *obj)
{
	t_ray	trace;
	t_vec3	*tmp;
	t_vec3	*point;
	t_light	*li;
	double	t;

	tmp = ft_vec3_scale(*r.d, r.t);
	point = ft_vec3_add(r.e, *tmp);
	while(obj)
	{
		if (obj->id == l)
		{
			li = obj->content;
			ft_memcpy(&trace.e, &li->point, sizeof(t_vec3));
			trace.d = ft_vec3_remove(*point, trace.e);
			trace.t = ft_vec3_len(*trace.d);
			t = trace.t;
			free(tmp);
			tmp = trace.d;
			trace.d = ft_vec3_normalize(*trace.d);
			free(tmp);
			ft_touch(&trace, u, obj, 1);
			if (trace.t >= 0.999 * t &&  trace.t <= 1.001 *t)
			{
				ft_diffuse_reflection(trace, u, *li);
				//ft_specular_reflection(r, trace, u, *li);
			}
		}
		obj = obj->next;
	}
	free(point);
}
