/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:53:22 by snpark            #+#    #+#             */
/*   Updated: 2022/02/21 12:34:59 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

float	measure_distance_to_sphere(float a, t_sphere *sp, t_ray cam)
{
	const t_vector	alpha = vec_subtract(cam.origin, sp->point);
	const float		b = vec_dot(cam.direction, alpha) * 2; 
	const float		c = vec_dot(alpha, alpha) - powf(sp->diameter, 2);
	float			discriminant;
	float			distance;

	discriminant = powf(b, 2.0) - 4 * a * c;
	if (discriminant < 0)
		return (-1);
	distance = -b / (2 * a);
	if (discriminant != 0)
		discriminant = fabsf(sqrtf(discriminant) / (2 * a));
	if (distance + discriminant <= 0)
		return (-1);
	if (distance - discriminant > 0)
		distance -= discriminant;
	else
		distance += discriminant;
	return (distance);
}

void	shoot_ray_to_sphere(t_pixel *p, t_sphere *sp, t_ray cam)
{
	const float		a = 1;//vec_dot(cam.direction, cam.direction);
	float			distance;

	while (sp)
	{
		distance = measure_distance_to_sphere(a, sp, cam);
		if (distance > 0 && !(p->touched && distance > p->distance))
		{
			p->touched = TRUE;
			p->distance = distance;
			p->point = vec_add(cam.origin, vec_scailing(cam.direction, distance));
			p->normal = vec_subtract(p->point, sp->point);
			p->obj_color = sp->color;
			p->address = sp;
		}
		sp = sp->next;
	}
}

void	shoot_ray_to_circle();

void	shoot_ray_to_cylinder();

void	shoot_ray_to_cone();//bonus

void	shoot_ray_to_plane();

t_pixel	shoot_ray(t_rt img_format, t_ray camera_ray)
{
	(void)img_format; (void)camera_ray;
	t_pixel			p;

	ft_memset(&p, 0, sizeof(t_pixel));
	shoot_ray_to_sphere(&p, img_format.sphere, camera_ray);
//	while (img_format.plane)
//	{
//		shoot_ray_to_plane();
//		img_format.plane = (t_plane *)img_format.plane->next;
//	}
//	while (img_format.cylinder)
//	{
//		shoot_ray_to_cylinder();
//		img_format.cylinder = (t_cylinder *)img_format.cylinder->next;
//	}
	return p;
}
