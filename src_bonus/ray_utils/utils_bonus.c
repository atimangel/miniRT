/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:31:18 by snpark            #+#    #+#             */
/*   Updated: 2022/02/25 17:04:49 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

void
	write_pixel_info(t_pixel *p, float distance, void *obj_address, t_ray cam)
{
	p->touched = TRUE;
	p->distance = distance;
	p->point = ray_to_vec(cam.origin, cam.direction, distance);
	p->address = obj_address;
}

float	get_distance(float a, float b, float c)
{
	float	discriminant;
	float	distance;

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

unsigned char	add_color(float c)
{
	if (c >= 255)
		return (255);
	return ((unsigned char)c);
}

