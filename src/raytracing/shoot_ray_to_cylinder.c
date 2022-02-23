/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_ray_to_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:30:18 by snpark            #+#    #+#             */
/*   Updated: 2022/02/23 17:32:50 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void
	shoot_ray_to_circle(t_pixel *p, t_cylinder *cy, t_ray cam, float height)
{
	const t_vector	circle_midpoint = vec_add(cy->point, \
			vec_scailing(cy->normal, height));
	const float		distance = \
			vec_dot(vec_subtract(circle_midpoint, cam.origin), cy->normal) \
			/ vec_dot(cam.direction, cy->normal);
	const float		diameter = vec_scala(vec_subtract(circle_midpoint, \
				vec_add(cam.origin, vec_scailing(cam.direction, distance))));

	if (diameter < -cy->diameter || diameter > cy->diameter)
		return ;
	if (distance > 0 && !(p->touched && distance > p->distance))
	{
		write_pixel_info(p, distance, cy, cam);
		p->normal = cy->normal;
		if (vec_cosine(cam.direction, p->normal) > 0)
			p->normal = vec_scailing(p->normal, -1);
		p->obj_color = cy->color;
	}
}

/*a - (a.b)*b*/
static t_vector	cylinder_coefficient(t_vector a, t_vector b)
{
	return (vec_subtract(a, vec_scailing(b, vec_dot(a, b))));
}

static void	shoot_ray_to_side(t_pixel *p, t_cylinder *cy, t_ray cam)
{
	const t_vector	alpha = cylinder_coefficient(cam.direction, cy->normal);
	const t_vector	beta = cylinder_coefficient(\
			vec_subtract(cam.origin, cy->point), cy->normal);
	const float		distance = get_distance(vec_dot(alpha, alpha), \
			2 * vec_dot(alpha, beta), \
			vec_dot(beta, beta) - powf(cy->diameter, 2));
	float			height;
	t_vector		hit_point;

	if (distance > 0 && !(p->touched && distance > p->distance))
	{
		hit_point = ray_to_vec(cam.origin, cam.direction, distance);
		height = vec_dot(cy->normal, vec_subtract(hit_point, cy->point));
		if (height < 0 || height > cy->height)
			return ;
		write_pixel_info(p, distance, cy, cam);
		p->normal = vec_normalize(vec_subtract(hit_point, \
					ray_to_vec(cy->point, cy->normal, height)));
		p->obj_color = cy->color;
	}
}

void	shoot_ray_to_cylinder(t_pixel *p, t_cylinder *cy, t_ray cam)
{
	while (cy)
	{
		shoot_ray_to_circle(p, cy, cam, 0);
		shoot_ray_to_circle(p, cy, cam, cy->height);
		shoot_ray_to_side(p, cy, cam);
		cy = cy->next;
	}
}
