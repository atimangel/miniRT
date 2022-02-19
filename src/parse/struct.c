/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:18:48 by snpark            #+#    #+#             */
/*   Updated: 2022/02/19 11:14:22 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static unsigned char	color_range_check(int num)
{
	if (num < 0 || num > 255)
		report_error("color data is out of range[0~255]\n");
	return (num);
}

static float	normal_vector_range_check(float num)
{
	if (num < 0.0f || num > 1.0f)
		report_error("normal vector out of range[0~1]\n");
	return (num);
}

t_color	parse_color(const char **line)
{
	t_color	color;

	color.r = color_range_check(ft_atoi(line));
	if (**line == ',')
		++(*line);
	color.g = color_range_check(ft_atoi(line));
	if (**line == ',')
		++(*line);
	color.b = color_range_check(ft_atoi(line));
	color.a = 0;
	return (color);
}

t_vector	parse_vector(const char **line)
{
	t_vector	vector;

	vector.x = ft_atof(line);
	if (**line == ',')
		++(*line);
	vector.y = ft_atof(line);
	if (**line == ',')
		++(*line);
	vector.z = ft_atof(line);
	return (vector);
}

t_vector	parse_normal_vector(const char **line)
{
	t_vector	vector;

	vector.x = normal_vector_range_check(ft_atof(line));
	if (**line == ',')
		++(*line);
	vector.y = normal_vector_range_check(ft_atof(line));
	if (**line == ',')
		++(*line);
	vector.z = normal_vector_range_check(ft_atof(line));
	//normalizing vector(&vector);
	return (vector);
}
