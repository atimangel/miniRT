/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_ray_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:53:22 by snpark            #+#    #+#             */
/*   Updated: 2022/02/28 11:36:13 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

static float	measure_distance_to_sphere(t_sphere *sp, t_ray cam)
{
	const float		a = 1;
	const t_vector	alpha = vec_subtract(cam.origin, sp->point);
	const float		b = vec_dot(cam.direction, alpha) * 2;
	const float		c = vec_dot(alpha, alpha) - powf(sp->diameter, 2);

	return (get_distance(a, b, c));
}

static void	shoot_ray_to_sphere(t_pixel *p, t_sphere *sp, t_ray cam)
{
	float			distance;

	while (sp)
	{
		distance = measure_distance_to_sphere(sp, cam);
		if (distance > 0 && !(p->touched && distance > p->distance))
		{
			write_pixel_info(p, distance, sp, cam);
			p->normal = vec_subtract(p->point, sp->point);
			p->obj_color = sp->color;
		}
		sp = sp->next;
	}
}

static void	shoot_ray_to_plane(t_pixel *p, t_plane *pl, t_ray cam)
{
	float	dot;
	float	distance;

	while (pl)
	{
		dot = vec_dot(pl->normal, cam.direction);
		if (dot != 0)
			distance = vec_dot(pl->normal, vec_subtract(pl->point, \
						cam.origin)) / vec_dot(pl->normal, cam.direction);
		if (distance > 0 && !(p->touched && distance > p->distance))
		{
			write_pixel_info(p, distance, pl, cam);
			p->normal = pl->normal;
			if (vec_dot(p->normal, cam.direction) > 0)
				p->normal = vec_scailing(p->normal, -1);
			p->obj_color = pl->color;
		}
		pl = pl->next;
	}
}

t_pixel	shoot_ray(t_rt img_format, t_ray camera_ray)
{
	t_pixel			p;

	ft_memset(&p, 0, sizeof(t_pixel));
	shoot_ray_to_sphere(&p, img_format.sphere, camera_ray);
	shoot_ray_to_plane(&p, img_format.plane, camera_ray);
	shoot_ray_to_cylinder(&p, img_format.cylinder, camera_ray);
	shoot_ray_to_cone(&p, img_format.cone, camera_ray);
	return (p);
}
