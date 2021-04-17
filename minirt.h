#ifndef MINIRT_H
# define MINIRT_H

#include "libft.h"
#include "libft_bonus.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}		t_mlx;

typedef struct s_pixel_map
{
	void	*img_ptr;
	void	*pixel_str;
	int	bpp;
	int	l_len;
	int	endian;
}		t_pixel_map;

typedef struct s_pixel_unit
{
	int	x;
	int	y;
	int	color;
}		t_pixel_unit;

void	ft_make_window(t_mlx *mlx);
void	ft_hook_event(t_mlx mlx);
void	ft_make_pixel_map(t_mlx mlx, t_pixel_map *pm);
void	ft_draw_pixel_map(t_mlx mlx, t_pixel_map pm);
#endif
