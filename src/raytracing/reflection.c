/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:59:52 by snpark            #+#    #+#             */
/*   Updated: 2022/02/21 12:35:32 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//utils?
static unsigned char	add_color(float c)
{
	if (c >= 255)
		return (255);
	return ((unsigned char)c);
}

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

float	vec_cosine(t_vector a, t_vector b)
{
	return (vec_dot(a, b) / (vec_scala(a) * vec_scala(b)));
}

t_color	diffuse_reflection(t_pixel p, const t_light light)
{
	const t_vector	to_light = vec_subtract(light.point, p.point);
	const float		cosine = vec_cosine(p.normal, to_light); 
//	const float		distance_ratio = 1 / powf(2, p.distance / LIGHT_RATIO_HARF_DISTANCE);
	const float distance_ratio = 1;
//
//	print_vector(light.point);
//	print_vector(p.point);
//	print_vector(to_light);
//	printf("cosine %f distance %f\n", cosine, p.distance);
	if (cosine > 0)
	{
		//거리에 따른 빛 밝기 나타내는 방식비교해보기
//		p.pix_color.r = add_color(p.obj_color.r * light.ratio * light.color.r / 255 / powf((1 + 0.001 * p.distance), 2));
//		p.pix_color.r = add_color(p.obj_color.r * light.ratio * light.color.r / 255 / powf((1 + 0.001 * p.distance), 2));
//		p.pix_color.r = add_color(p.obj_color.r * light.ratio * light.color.r / 255 / powf((1 + 0.001 * p.distance), 2));
		p.pix_color.r = add_color(p.obj_color.r * cosine * light.color.r * light.ratio * distance_ratio / 255 + p.pix_color.r);
		p.pix_color.g = add_color(p.obj_color.g * cosine * light.color.g * light.ratio * distance_ratio / 255 + p.pix_color.g);
		p.pix_color.b = add_color(p.obj_color.b * cosine * light.color.b * light.ratio * distance_ratio / 255 + p.pix_color.b);
	}
	return (p.pix_color);
}


t_color	light_reflection(t_pixel obj, t_rt img_format)
{
	t_pixel	hit_obj;
	t_ray	light;
	float	range;

	while (img_format.light)
	{
		light.origin = img_format.light->point;
		light.direction = vec_normalize(vec_subtract(obj.point, img_format.light->point));
		range = vec_scala(vec_subtract(obj.point, img_format.light->point));
		hit_obj = shoot_ray(img_format, light);
		obj.pix_color = diffuse_reflection(obj, *img_format.light);
		if (!(hit_obj.touched == TRUE && hit_obj.distance > range) || obj.address == hit_obj.address)
		{
			obj.pix_color = diffuse_reflection(obj, *img_format.light);
			//obj.pix_color = specular_reflection();
		}
		img_format.light = img_format.light->next;
	}
	return (obj.pix_color);
}
