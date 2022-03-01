/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_ray_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:53:22 by snpark            #+#    #+#             */
/*   Updated: 2022/03/01 23:02:33 by snpark           ###   ########.fr       */
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

t_vector	bump_mapping(t_plane *pl, t_vector coord)
{
	t_vector	pixel_normal;
	t_vector	bumpped_normal;
	int			x;
	int			y;
	int			pixel;

	x = (int)(vec_dot(coord, pl->bump.x) * pl->bump.width / 20) % \
		pl->bump.width;
	y = (int)(vec_dot(coord, pl->bump.y) * pl->bump.height / 20) % \
		pl->bump.height;
	if (x < 0)
		x = pl->bump.width + x;
	if (y < 0)
		y = pl->bump.height + y;
	pixel = pl->bump.buffer[pl->bump.width * y + x];
	pixel_normal.x = (float)(((pixel >> 16) & 0xff) * 2 - 255) / 255;
	pixel_normal.y = (float)(((pixel >> 8) & 0xff) * 2 - 255) / 255;
	pixel_normal.z = (float)((pixel & 0xff) * 2 - 255 ) / 255;
	bumpped_normal.x = pixel_normal.x * pl->bump.x.x + \
				pixel_normal.y * pl->bump.y.x + pixel_normal.z * pl->bump.z.x;
	bumpped_normal.y = pixel_normal.x * pl->bump.x.y + \
				pixel_normal.y * pl->bump.y.y + pixel_normal.z * pl->bump.z.y;
	bumpped_normal.z = pixel_normal.x * pl->bump.x.z + \
				pixel_normal.y * pl->bump.y.z + pixel_normal.z * pl->bump.z.z;
	return (bumpped_normal);
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
			if (pl->bump.name)
				p->normal = bump_mapping(pl, vec_subtract(\
				ray_to_vec(cam.origin, cam.direction, distance), pl->point));
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
