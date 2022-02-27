/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:24:24 by snpark            #+#    #+#             */
/*   Updated: 2022/02/27 13:03:38 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

t_vector	vec_reflect(t_vector normal, t_vector ray)
{
	return (vec_normalize(vec_add(\
					vec_scailing(normal, -vec_dot(ray, normal) * 2), ray)));
}
