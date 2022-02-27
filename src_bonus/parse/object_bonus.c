/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:04:07 by snpark            #+#    #+#             */
/*   Updated: 2022/02/27 13:04:13 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

void	parse_sphere(const char *line, t_rt *img_format, t_bool *flag)
{
	const t_sphere	*head = img_format->sphere;

	if (!(*line == 's' && *(line + 1) == 'p' && \
				(*(line + 2) == ' ' || *(line + 2) == '\t')))
		return ;
	line += 3;
	*flag = TRUE;
	++img_format->count.sphere;
	if (head)
	{
		while (img_format->sphere && img_format->sphere->next)
			img_format->sphere = (t_sphere *)img_format->sphere->next;
		img_format->sphere->next = xcalloc(sizeof(t_sphere));
		img_format->sphere = (t_sphere *)img_format->sphere->next;
	}
	else
		img_format->sphere = xcalloc(sizeof(t_sphere));
	img_format->sphere->point = parse_vector(&line);
	img_format->sphere->diameter = parse_length(&line);
	img_format->sphere->color = parse_color(&line);
	img_format->sphere->next = NULL;
	parse_wrap_up(line, (void **)&img_format->sphere, (void *)head);
}

void	parse_plane(const char *line, t_rt *img_format, t_bool *flag)
{
	const t_plane	*head = img_format->plane;

	if (!(*line == 'p' && *(line + 1) == 'l' && \
				(*(line + 2) == ' ' || *(line + 2) == '\t')))
		return ;
	line += 3;
	*flag = TRUE;
	++img_format->count.plane;
	if (head)
	{
		while (img_format->plane->next)
			img_format->plane = (t_plane *)img_format->plane->next;
		img_format->plane->next = xcalloc(sizeof(t_plane));
		img_format->plane = (t_plane *)img_format->plane->next;
	}
	else
		img_format->plane = xcalloc(sizeof(t_plane));
	img_format->plane->point = parse_vector(&line);
	img_format->plane->normal = parse_normal_vector(&line);
	img_format->plane->color = parse_color(&line);
	img_format->plane->next = NULL;
	parse_wrap_up(line, (void **)&img_format->plane, (void *)head);
}

void	parse_cylinder(const char *line, t_rt *img_format, t_bool *flag)
{
	const t_cylinder	*head = img_format->cylinder;

	if (!(*line == 'c' && *(line + 1) == 'y' && \
				(*(line + 2) == ' ' || *(line + 2) == '\t')))
		return ;
	line += 3;
	*flag = TRUE;
	++img_format->count.cylinder;
	if (head)
	{
		while (img_format->cylinder && img_format->cylinder->next)
			img_format->cylinder = (t_cylinder *)img_format->cylinder->next;
		img_format->cylinder->next = xcalloc(sizeof(t_cylinder));
		img_format->cylinder = (t_cylinder *)img_format->cylinder->next;
	}
	else
		img_format->cylinder = xcalloc(sizeof(t_cylinder));
	img_format->cylinder->point = parse_vector(&line);
	img_format->cylinder->normal = parse_normal_vector(&line);
	img_format->cylinder->diameter = parse_length(&line);
	img_format->cylinder->height = parse_length(&line);
	img_format->cylinder->color = parse_color(&line);
	img_format->cylinder->next = NULL;
	parse_wrap_up(line, (void **)&img_format->cylinder, (void *)head);
}

void	parse_cone(const char *line, t_rt *img_format, t_bool *flag)
{
	const t_cone	*head = img_format->cone;

	if (!(*line == 'c' && *(line + 1) == 'o' && \
				(*(line + 2) == ' ' || *(line + 2) == '\t')))
		return ;
	line += 3;
	*flag = TRUE;
	++img_format->count.cone;
	if (head)
	{
		while (img_format->cone && img_format->cone->next)
			img_format->cone = (t_cone *)img_format->cone->next;
		img_format->cone->next = xcalloc(sizeof(t_cone));
		img_format->cone = (t_cone *)img_format->cone->next;
	}
	else
		img_format->cone = xcalloc(sizeof(t_cone));
	img_format->cone->point = parse_vector(&line);
	img_format->cone->normal = parse_normal_vector(&line);
	img_format->cone->diameter = parse_length(&line);
	img_format->cone->height = parse_length(&line);
	img_format->cone->color = parse_color(&line);
	img_format->cone->next = NULL;
	parse_wrap_up(line, (void **)&img_format->cone, (void *)head);
}

void	parse_light(const char *line, t_rt *img_format, t_bool *flag)
{
	const t_light	*head = img_format->light;

	if (!(*line == 'L' && (*(line + 1) == ' ' || *(line + 1) == '\t')))
		return ;
	line += 2;
	*flag = TRUE;
	++img_format->count.light;
	if (head)
	{
		while (img_format->light && img_format->light->next)
			img_format->light = (t_light *)img_format->light->next;
		img_format->light->next = xcalloc(sizeof(t_light));
		img_format->light = (t_light *)img_format->light->next;
	}
	else
		img_format->light = xcalloc(sizeof(t_light));
	img_format->light->point = parse_vector(&line);
	img_format->light->ratio = parse_ratio(&line);
	img_format->light->color = parse_color(&line);
	img_format->light->next = NULL;
	parse_wrap_up(line, (void **)&img_format->light, (void *)head);
}
