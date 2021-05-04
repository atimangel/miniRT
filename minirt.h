#ifndef MINIRT_H
# define MINIRT_H

#include "libft.h"
#include "libft_bonus.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

enum e_obj {R = 1, A, c, l, sp, pl, sq, cy, tr};

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
	enum e_obj		id;
	t_vec3			point;
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
	enum e_obj	id;
	t_vec3		center;
	t_vec3		normal;
	unsigned char	red;
	unsigned char	green;
	unsigned char 	blue;
}		t_plane;

typedef struct	s_sphere
{
	enum e_obj	id;
	t_vec3		center;
	double		radius;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}		t_sphere;

typedef struct	s_square
{
	enum e_obj	id;
	t_vec3		center;
	t_vec3		normal;
	double		len;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}		t_square;

typedef struct s_resolution
{
	enum e_obj	id;
	int		x;
	int		y;
}		t_resolution;

typedef struct s_ambient_reflection
{
	enum e_obj	id;
	double		ratio;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}		t_ambient_reflection;

typedef struct s_camera
{
	enum e_obj	id;
	t_vec3		camera;
	t_vec3		direction;
	double		fov;
}		t_camera;

void	ft_make_window(t_mlx *mlx, t_list *obj);
void	ft_hook_event(t_mlx mlx);
void	ft_make_pixel_map(t_mlx mlx, t_pixel_map *pm, t_list *obj);
void	ft_draw_pixel_map(t_mlx mlx, t_pixel_map pm, t_list *obj);
void	ft_sphere_touch(t_ray *r, t_pixel_unit *u);
void	ft_plane_touch(t_ray *r, t_pixel_unit *u);
void	ft_triangle_touch(t_ray *r, t_pixel_unit *u);
void	ft_square_touch(t_ray *r, t_pixel_unit *u);
void	ft_cylinder_touch(t_ray *r, t_pixel_unit *u);
void	ft_ambient_reflection(t_pixel_unit *u, t_list *obj);
void	ft_diffuse_reflection(t_ray *r, t_pixel_unit *u, t_light light);
void	ft_specular_reflection(t_ray *r, t_pixel_unit *u, t_light light);
void	ft_light_max(t_pixel_unit *u);

t_list	*ft_parse_rt(char *filename);

char	*ft_read_float(char *line, double *vec, char flag);
char	*ft_pass_space(char *line);
char	*ft_read_char(char *line, char *rgb, char flag);

void	*ft_make_resolution(char *line);
void	*ft_make_ambient_reflection(char *line);
void	*ft_make_camera(char *line);
void	*ft_make_light(char *line);
void	*ft_make_sphere(char *line);
void	*ft_make_plane(char *line);
void	*ft_make_square(char *line);
#endif

