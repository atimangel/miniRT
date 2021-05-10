#include "minirt.h"

char	ft_isshadow()
{

}

void	ft_reflection(t_ray *r, t_pixel_unit *u, t_list *obj)
{
	t_ray	trace;
	t_vec3	*tmp;
	t_light	*li;

	tmp = ft_vec3_scale(*r->d, r->t);
	trace.d = ft_vec3_add(r->e, *tmp);
	free(tmp);
	trace.t = 1.0;
	while(obj)
	{
		if (obj->id == l)
		{
			li = obj->content;
			ft_memcpy(&trace.e, &li->point, sizeof(t_vec3));
			if (!ft_isshadow(trace, obj))//0 == light 1 == shadow
			{
				ft_diffuse_reflection();
				ft_specular_reflection();
			}
		}
		obj = obj->next;
	}
}
