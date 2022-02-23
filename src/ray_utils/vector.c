/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:51:04 by snpark            #+#    #+#             */
/*   Updated: 2022/02/23 17:30:23 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

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

float	vec_scala(t_vector v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}
