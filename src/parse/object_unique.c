/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_unique.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:43:02 by snpark            #+#    #+#             */
/*   Updated: 2022/02/19 11:13:20 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	parse_ambient(const char *line, t_rt *img_format, t_bool *flag)
{
	if (!(*line == 'A' && (*(line + 1) == ' ' || *(line + 1) == '\t')))
		return ;
	if (img_format->count.ambient)
		report_error("please assign Ambient once in .rt file\n");
	line += 2;
	*flag = TRUE;
	img_format->count.ambient = TRUE;
	img_format->amb.ratio = parse_ratio(&line);
	img_format->amb.color = parse_color(&line);
	skip_space(&line);
	if (*line)
		report_error("amb format error\n");
}

void	parse_camera(const char *line, t_rt *img_format, t_bool *flag)
{
	if (!(*line == 'C' && (*(line + 1) == ' ' || *(line + 1) == '\t')))
		return ;
	if (img_format->count.camera)
		report_error("please assign Camera once in .rt file\n");
	line += 2;
	*flag = TRUE;
	img_format->count.camera = TRUE;
	img_format->cam.view_point = parse_vector(&line);
	img_format->cam.normalized_oriention_vector = parse_normal_vector(&line);
	img_format->cam.horizontal_field_of_view = parse_angle(&line);
	skip_space(&line);
	if (*line)
		report_error("cam format error\n");
}
