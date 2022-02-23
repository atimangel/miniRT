/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:51:04 by snpark            #+#    #+#             */
/*   Updated: 2022/02/22 12:36:03 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

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

float		vec_scala(t_vector v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vector	vec_normalize(t_vector v)
{
	const float	scala = vec_scala(v);
	
	v.x /= scala;
	v.y /= scala;
	v.z /= scala;
	return (v);
}

t_vector	vec_add(t_vector a, t_vector b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vector	vec_subtract(t_vector a, t_vector b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_vector	vec_scailing(t_vector a, float scala)
{
	a.x *= scala;
	a.y *= scala;
	a.z *= scala;
	return (a);
}

float		tan_d(float degree)
{
	static const float	radian = M_PI / 180;

	return (tan(degree * radian));
}

t_vector	vec_reflect();
