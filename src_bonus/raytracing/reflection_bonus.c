/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:59:52 by snpark            #+#    #+#             */
/*   Updated: 2022/03/01 23:03:08 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

t_color	ambient_reflection(t_pixel p, t_amb_light light)
{
	p.pix_color.r = add_color(p.obj_color.r * light.color.r * light.ratio \
			/ 255);
	p.pix_color.g = add_color(p.obj_color.g * light.color.g * light.ratio \
			/ 255);
	p.pix_color.b = add_color(p.obj_color.b * light.color.b * light.ratio \
			/ 255);
	return (p.pix_color);
}

t_color	diffuse_reflection(t_pixel p, const t_light light)
{
	const t_vector	to_light = vec_subtract(light.point, p.point);
	const float		cosine = vec_cosine(p.normal, to_light);
	const float		distance_ratio = \
						1 / powf(2, p.distance / LIGHT_RATIO_HARF_DISTANCE);
	const float		ratio = cosine * light.ratio * distance_ratio / 255;

	if (cosine > 0)
	{
		p.pix_color.r = \
			add_color(p.obj_color.r * light.color.r * ratio + p.pix_color.r);
		p.pix_color.g = \
			add_color(p.obj_color.g * light.color.g * ratio + p.pix_color.g);
		p.pix_color.b = \
			add_color(p.obj_color.b * light.color.b * ratio + p.pix_color.b);
	}
	return (p.pix_color);
}

t_color	specular_reflection(t_pixel p, const t_light light, \
		const t_ray cam, const t_ray light_ray)
{
	const float	cosine = \
		-vec_dot(vec_reflect(p.normal, light_ray.direction), cam.direction);
	const float	distance_ratio = \
		1 / powf(2, p.distance / LIGHT_RATIO_HARF_DISTANCE);
	const float	specular_ratio = powf(cosine, 128);
	const float	ratio = specular_ratio * light.ratio * distance_ratio;

	if (cosine > 0)
	{
		p.pix_color.r = add_color(light.color.r * ratio + p.pix_color.r);
		p.pix_color.g = add_color(light.color.g * ratio + p.pix_color.g);
		p.pix_color.b = add_color(light.color.b * ratio + p.pix_color.b);
	}
	return (p.pix_color);
}

t_color	light_reflection(t_pixel obj, t_rt img_format, t_ray cam)
{
	t_pixel	hit_obj;
	t_ray	light;
	float	range;

	while (img_format.light)
	{
		light.origin = img_format.light->point;
		light.direction = \
				vec_normalize(vec_subtract(obj.point, img_format.light->point));
		range = vec_scala(vec_subtract(obj.point, img_format.light->point));
		hit_obj = shoot_ray(img_format, light);
		if (hit_obj.address == obj.address)
		{
			obj.pix_color = diffuse_reflection(obj, *img_format.light);
			obj.pix_color = specular_reflection(obj, \
					*img_format.light, cam, light);
		}
		img_format.light = img_format.light->next;
	}
	return (obj.pix_color);
}
