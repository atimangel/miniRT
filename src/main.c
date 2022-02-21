/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:22:51 by snpark            #+#    #+#             */
/*   Updated: 2022/02/21 11:35:41 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

#include <stdio.h>

void	print_color(t_color c)
{
	printf("color: %d %d %d ", c.r, c.g, c.b);
}

void	print_vector(t_vector v)
{
	printf("vector: %f %f %f ", v.x, v.y, v.z);
}

void	print_img_format(t_rt img)
{	
	if (img.count.ambient)
	{
		printf("A ratio %f ", img.amb.ratio);
		print_color(img.amb.color);
		printf("\n");
	}
	if (img.count.camera)
	{
		printf("C ");
		print_vector(img.cam.view_point);
		print_vector(img.cam.normal);
		printf("fov %f\n", img.cam.h_fov);
	}
	while (img.count.light--)
	{
		printf("L ");
		print_vector(img.light->point);
		printf("ratio %f ", img.light->ratio);
		print_color(img.light->color);
		printf("\n");
		img.light = img.light->next;
	}
	int i = 0;
	while (img.count.sphere--)
	{
		printf("sp[%d] ", ++i);
		print_vector(img.sphere->point);
		printf("diameter %f ", img.sphere->diameter);
		print_color(img.sphere->color);
		printf("\n");
		img.sphere = (t_sphere *)img.sphere->next;
	}
	i = 0;
	while (img.count.cylinder--)
	{
		printf("cy[%d] ", ++i);
		print_vector(img.cylinder->point);
		print_vector(img.cylinder->normal);
		printf("diameter %f height %f ", img.cylinder->diameter, img.cylinder->height);
		print_color(img.cylinder->color);
		printf("\n");
		img.cylinder = img.cylinder->next;
	}
	i = 0;
	while (img.count.plane--)
	{
		printf("pl[%d] ", ++i);
		print_vector(img.plane->point);
		print_vector(img.plane->normal);
		print_color(img.plane->color);
		printf("\n");
		img.plane = img.plane->next;
	}
}

int	main(int argc, char **argv)
{
	(void)argc; (void)argv;
	t_rt	img_format;
	t_mlx	mlx;


	ft_memset(&img_format, 0, sizeof(t_rt));
	if (argc != 2 || !is_rtfile(argv[1]))
		report_error("argument should be a .rt file\n");
	parse(argv[1], &img_format);
	img_plane_unit(&img_format.cam);

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "miniRT");

	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.buffer = (unsigned int *)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.llen, &mlx.endian);

	raytracing(img_format, mlx.buffer);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
	//ray tracing
		//view plane & camera ray
		//shoot ray by pixel
		//make img;
	//mlx
	//	make window
	//	wait event
}
