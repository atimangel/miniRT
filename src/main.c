/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:22:51 by snpark            #+#    #+#             */
/*   Updated: 2022/02/23 18:50:55 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	red_button(int key_num, void *parm)
{
	(void)key_num;
	(void)parm;
	exit(1);
}

static int	key_event(int key_num, void *parm)
{
	(void)parm;
	if (key_num == 53)
		exit(1);
	return (0);
}

static void	mlx_initialize(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "miniRT");
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->buffer = (unsigned int *)mlx_get_data_addr(mlx->img, \
			&mlx->bpp, &mlx->llen, &mlx->endian);
	mlx_key_hook(mlx->win, key_event, (void *)&mlx);
	mlx_hook(mlx->win, 17, 0, red_button, (void *)&mlx);
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
	raytracing(img_format, mlx.buffer);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
}
