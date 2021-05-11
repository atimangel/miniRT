#include "minirt.h"

void	ft_reflection(t_ray r, t_pixel_unit *u, t_list *obj)
{
	t_ray	trace;
	t_vec3	*tmp;
	t_light	*li;

	tmp = ft_vec3_scale(*r.d, r.t);
	trace.d = ft_vec3_add(r.e, *tmp);
	free(tmp);
	while(obj)
	{
		if (obj->id == l)
		{
			trace.t = 1.0;
			li = obj->content;
			ft_memcpy(&trace.e, &li->point, sizeof(t_vec3));
			ft_touch(&trace, u, obj, 1);
			if (trace.t == 1.0)
			{
				ft_diffuse_reflection(trace, u, *li);
				//ft_specular_reflection(r, trace, u, *li);
			}
		}
		obj = obj->next;
	}
}
