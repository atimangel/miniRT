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
	unsigned char o_r;
	unsigned char o_g;
	unsigned char o_b;
	t_vec3		*o_n;
	int p_r;
	int p_g;
	int p_b;
}		t_pixel_unit;

typedef struct s_ray
{
	t_vec3	*e;
	t_vec3	*d;
	double	t;
}				t_ray;

typedef struct s_light
{
	t_vec3			*c;
	double			ratio;
	unsigned char	red;
	unsigned char 	green;
	unsigned char	blue;
}				t_light;

typedef struct s_image_plane
{
	t_vec3		*camera;
	t_vec3		*direction;
	double		fob_h;
	double		fob_v;
	t_vec3		*abs_up;
	t_vec3		*right;
	t_vec3		*up;
	double		len_h;
	double		len_v;
	int		x;
	int		y;
}		t_image_plane;

typedef struct s_cylinder
{
	t_vec3		*c;
	t_vec3		*n;
	t_vec3		*c2;
	double		r;
	double		h;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}		t_cylinder;

typedef struct	s_plane
{
	t_vec3		*center;
	t_vec3		*normal;
	unsigned char	red;
	unsigned char	green;
	unsigned char 	blue;
}		t_plane;

typedef struct	s_sphere
{
	t_vec3		*center;
	double		radius;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}		t_sphere;

typedef struct	s_square
{
	t_vec3		*center;
	t_vec3		*normal;
	double		len;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}		t_square;

void	ft_make_window(t_mlx *mlx);
void	ft_hook_event(t_mlx mlx);
void	ft_make_pixel_map(t_mlx mlx, t_pixel_map *pm);
void	ft_draw_pixel_map(t_mlx mlx, t_pixel_map pm);
void	ft_sphere_touch(t_ray *r, t_pixel_unit *u);
void	ft_plane_touch(t_ray *r, t_pixel_unit *u);
void	ft_triangle_touch(t_ray *r, t_pixel_unit *u);
void	ft_square_touch(t_ray *r, t_pixel_unit *u);
void	ft_cylinder_touch(t_ray *r, t_pixel_unit *u);
void	ft_ambient_reflection(t_pixel_unit *u);
void	ft_make_light(t_light *light);
void	ft_diffuse_reflection(t_ray *r, t_pixel_unit *u, t_light light);
void	ft_specular_reflection(t_ray *r, t_pixel_unit *u, t_light light);
void	ft_light_max(t_pixel_unit *u);

int	ft_parse_rt(char *filename, void **object_list);
#endif

