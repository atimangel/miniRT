/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:49:32 by snpark            #+#    #+#             */
/*   Updated: 2022/02/28 09:30:24 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

void	filter(t_mlx *mlx)
{
	const int		buffer_len = WIDTH * HEIGHT;
	int				i;
	unsigned int	tmp;

	i = -1;
	tmp = 0;
	while (++i < buffer_len)
	{
		tmp = mlx->buffer[i];
		mlx->buffer[i] = (int)(((tmp >> 16) & 0xff) * 1) << 16;
		mlx->buffer[i] += (int)(((tmp >> 8) & 0xff) * 0) << 8; 
		mlx->buffer[i] += (tmp & 0xff) * 0; 
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
