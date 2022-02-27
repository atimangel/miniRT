/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:26:13 by snpark            #+#    #+#             */
/*   Updated: 2022/02/27 19:53:04 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

void	img_plane_unit(t_camera *cam)
{
	const t_vector	y_axis = {{0.0, 1.0, 0.0}};

	cam->unit_right = vec_normalize(vec_cross(cam->normal, y_axis));
	cam->unit_up = vec_normalize(vec_cross(cam->unit_right, cam->normal));
	cam->distance_to_img_plane = (float)WIDTH / 2 / tan_d(cam->h_fov / 2);
	cam->img_plane_origin = vec_add(cam->view_point, vec_add(\
				vec_scailing(cam->unit_right, -(float)(WIDTH - 1) / 2),
				vec_scailing(cam->unit_up, -(float)(HEIGHT - 1) / 2)));
}

static t_vector	get_normal_camera_ray(t_resolution coord, t_camera cam)
{
	t_vector	camera_ray;

	coord.y = HEIGHT - coord.y - 1;
	camera_ray = vec_add(cam.img_plane_origin, vec_add(\
				vec_scailing(cam.unit_right, coord.x),
				vec_scailing(cam.unit_up, coord.y)));
	camera_ray = vec_add(camera_ray, \
			vec_scailing(cam.normal, cam.distance_to_img_plane));
	camera_ray = vec_normalize(camera_ray);
	return (camera_ray);
}

static t_resolution	get_next_coordinate(t_resolution coord)
{
	++coord.y;
	if (coord.y == HEIGHT)
	{
		coord.y = 0;
		++coord.x;
	}
	return (coord);
}

static unsigned int	get_color(t_color col)
{
	return ((col.r << 16) + (col.g << 8) + col.b);
}

void	*raytracing(t_rt img_format, unsigned int *buffer)
{
	t_resolution	coordinate;
	t_ray			camera_ray;
	t_pixel			pixel_info;

	coordinate.x = 0;
	coordinate.y = 0;
	camera_ray.origin = img_format.cam.view_point;
	while (coordinate.x < WIDTH && coordinate.y < HEIGHT)
	{
		ft_memset(&pixel_info, 0, sizeof(t_pixel));
		camera_ray.direction = \
						get_normal_camera_ray(coordinate, img_format.cam);
		pixel_info = shoot_ray(img_format, camera_ray);
		if (pixel_info.touched)
		{
			pixel_info.pix_color = \
							ambient_reflection(pixel_info, img_format.amb);
			pixel_info.pix_color = light_reflection(\
					pixel_info, img_format, camera_ray);
		}
		buffer[WIDTH * coordinate.y + coordinate.x] = \
											get_color(pixel_info.pix_color);
		coordinate = get_next_coordinate(coordinate);
	}
	return (buffer);
}
