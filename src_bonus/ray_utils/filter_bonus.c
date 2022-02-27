/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:49:32 by snpark            #+#    #+#             */
/*   Updated: 2022/02/27 13:04:33 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

void	filter(t_color *buffer, t_mlx mlx)
{
	const int		buffer_len = WIDTH * HEIGHT;
	int				i;
	const float		x_ratio = 0.5;
	const float		y_ratio = 0.5;
	const float		z_ratio = 0.5;

	i = -1;
	while (++i < buffer_len)
	{
		if (!mlx.endian)
		{
			buffer->r = add_color(buffer->r + buffer->r * 0.5);
			buffer->g = add_color(buffer->g + buffer->g * 0.5);
			buffer->b = add_color(buffer->b + buffer->b * 0.5);
		}
		else
		{
			buffer->g = add_color(buffer->g + buffer->g * 0.5);
			buffer->r = add_color(buffer->r + buffer->r * 0.5);
			buffer->a = add_color(buffer->a + buffer->a * 0.5);
		}
	}
}
