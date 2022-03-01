/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:22:51 by snpark            #+#    #+#             */
/*   Updated: 2022/03/01 22:56:52 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt_bonus.h"

static int	red_button(int key_num, void *parm)
{
	(void)key_num;
	(void)parm;
	exit(1);
}

static int	key_event(int key_num, void *parm)
{
	t_mlx	*mlx;

	mlx = parm;
	if (key_num == 53)
		exit(1);
	if (key_num == 49)
		filter(mlx);
	return (0);
}

static void	mlx_initialize(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "miniRT");
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->buffer = (unsigned int *)mlx_get_data_addr(mlx->img, \
			&mlx->bpp, &mlx->llen, &mlx->endian);
	mlx_key_hook(mlx->win, key_event, (void *)mlx);
	mlx_hook(mlx->win, 17, 0, red_button, (void *)mlx);
}

void	open_bump_map(t_mlx mlx, t_plane *pl, t_camera cam)
{
	int	tmp;

	while (pl)
	{
		if (pl->bump.name)
		{
			pl->bump.img = mlx_xpm_file_to_image(mlx.mlx, pl->bump.name, \
					&pl->bump.width, &pl->bump.height);
			if (pl->bump.img == NULL)
				report_error("bump map open error\n");
			pl->bump.buffer = (unsigned int *)mlx_get_data_addr(pl->bump.img, \
					&tmp, &tmp, &tmp);
			if (vec_dot(pl->normal, cam.normal) > 0)
				pl->normal = vec_scailing(pl->normal, -1);
			pl->bump.z = pl->normal;
			tangent_space(&pl->bump);
		}
		pl = pl->next;
	}
}

int	main(int argc, char **argv)
{
	t_rt	img_format;
	t_mlx	mlx;

	ft_memset(&img_format, 0, sizeof(t_rt));
	if (argc != 2 || !is_rtfile(argv[1]))
		report_error("argument should be a .rt file\n");
	parse(argv[1], &img_format);
	img_plane_unit(&img_format.cam);
	mlx_initialize(&mlx);
	open_bump_map(mlx, img_format.plane, img_format.cam);
	raytracing(img_format, mlx.buffer);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
}
