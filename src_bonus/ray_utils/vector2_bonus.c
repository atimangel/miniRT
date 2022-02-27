/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:27:05 by snpark            #+#    #+#             */
/*   Updated: 2022/02/25 15:10:55 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

t_vector	ray_to_vec(t_vector o, t_vector d, float t)
{
	return (vec_add(o, vec_scailing(d, t)));
}

float	vec_cosine(t_vector a, t_vector b)
{
	return (vec_dot(a, b) / (vec_scala(a) * vec_scala(b)));
}

t_vector	vec_cross(t_vector x, t_vector y)
{
	t_vector	z;

	z.x = x.y * y.z - x.z * y.y;
	z.y = x.z * y.x - x.x * y.z;
	z.z = x.x * y.y - x.y * y.x;
	return (z);
}

float	vec_dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float	tan_d(float degree)
{
	static const float	radian = M_PI / 180;

	return (tan(degree * radian));
}
