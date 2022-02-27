/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:42:32 by snpark            #+#    #+#             */
/*   Updated: 2022/02/25 15:07:51 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

float	parse_angle(const char **line)
{
	float	angle;

	angle = ft_atof(line);
	if (angle <= 0.0f || angle >= 180.0f)
		report_error("format error angle range[0~180]\n");
	return (angle);
}

float	parse_length(const char **line)
{
	float	length;

	length = ft_atof(line);
	if (length < 0)
		report_error("length should be 0 and positive\n");
	return (length);
}

float	parse_ratio(const char **line)
{
	float	ratio;

	ratio = ft_atof(line);
	if (ratio < 0 || ratio > 1)
		report_error("ratio is out of range[0~1]\n");
	return (ratio);
}
