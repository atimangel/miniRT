/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_ray_to_cone_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:57:25 by snpark            #+#    #+#             */
/*   Updated: 2022/03/01 22:58:06 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

static void
	shoot_ray_to_circle(t_pixel *p, t_cone *co, t_ray cam, float height)
{
	const t_vector	circle_midpoint = vec_add(co->point, \
			vec_scailing(co->normal, height));
	const float		distance = \
			vec_dot(vec_subtract(circle_midpoint, cam.origin), co->normal) \
			/ vec_dot(cam.direction, co->normal);
	const float		diameter = vec_scala(vec_subtract(circle_midpoint, \
				vec_add(cam.origin, vec_scailing(cam.direction, distance))));

	if (diameter < -co->diameter || diameter > co->diameter)
		return ;
	if (distance > 0 && !(p->touched && distance > p->distance))
	{
		write_pixel_info(p, distance, co, cam);
		p->normal = co->normal;
		if (vec_cosine(cam.direction, p->normal) > 0)
			p->normal = vec_scailing(p->normal, -1);
		p->obj_color = co->color;
	}
}

float	get_distance_cone(t_cone co, t_ray cam)
{
	const float		ratio = powf(co.cos, 2);
	const t_vector	w = vec_subtract(cam.origin, co.point);
	const float		a = powf(vec_dot(cam.direction, co.normal), 2) - ratio;
	const float		b = 2 * (vec_dot(cam.direction, co.normal) * \
				vec_dot(w, co.normal) - vec_dot(cam.direction, w) * ratio);
	const float		c = powf(vec_dot(w, co.normal), 2) - vec_dot(w, w) * ratio;

	return (get_distance(a, b, c));
}

static void	shoot_ray_to_side(t_pixel *p, t_cone *co, t_ray cam)
{
	const float		distance = get_distance_cone(*co, cam);
	float			height;
	t_vector		hit_point;

	if (distance > 0 && !(p->touched && distance > p->distance))
	{
		hit_point = ray_to_vec(cam.origin, cam.direction, distance);
		height = vec_dot(co->normal, vec_subtract(hit_point, co->point));
		if (height < 0 || height > co->height)
			return ;
		write_pixel_info(p, distance, co, cam);
		p->normal = vec_normalize(\
					vec_add(vec_scailing(co->normal, -co->diameter), \
					vec_scailing(vec_normalize(vec_subtract(hit_point, \
					ray_to_vec(co->point, co->normal, height))), co->height)));
		p->obj_color = co->color;
	}
}

void	shoot_ray_to_cone(t_pixel *p, t_cone *co, t_ray cam)
{
	while (co)
	{
		co->cos = \
				co->height / sqrtf(powf(co->height, 2) + powf(co->diameter, 2));
		shoot_ray_to_circle(p, co, cam, co->height);
		shoot_ray_to_side(p, co, cam);
		co = co->next;
	}
}
