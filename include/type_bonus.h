/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:50:45 by snpark            #+#    #+#             */
/*   Updated: 2022/03/01 17:46:18 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_BONUS_H
# define TYPE_BONUS_H

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned int	*buffer;
	int				bpp;
	int				llen;
	int				endian;
}	t_mlx;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_resolution
{
	unsigned int	x;
	unsigned int	y;
}	t_resolution;

typedef struct s_count
{
	t_bool	ambient;
	t_bool	camera;
	int		light;
	int		sphere;
	int		plane;
	int		cylinder;
	int		cone;
}	t_count;

typedef struct s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}	t_color;

typedef union u_vector
{
	struct
	{
		float	x;
		float	y;
		float	z;
	};
	float		coordinate[3];
}	t_vector;

typedef struct s_amb_light
{
	float	ratio;	
	t_color	color;
}	t_amb_light;

typedef struct s_camera
{
	t_vector	view_point;
	t_vector	normal;
	t_vector	unit_right;
	t_vector	unit_up;
	t_vector	img_plane_origin;
	float		distance_to_img_plane;
	float		h_fov;
}	t_camera;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}	t_ray;

typedef struct s_pixel
{
	t_bool		touched;
	union	
	{	
		struct
		{
			t_vector	point;
			t_vector	normal;
		};
		t_ray	ray;
	};
	t_color		obj_color;
	t_color		pix_color;
	float		distance;
	void		*address;
}	t_pixel;

typedef struct s_light
{
	t_vector		point;
	float			ratio;
	t_color			color;
	struct s_light	*next;
}	t_light;

typedef struct s_sphere
{
	t_vector		point;
	float			diameter;
	t_color			color;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_bump
{
	char			*name;
	void			*img;
	unsigned int	*buffer;
	int				width;
	int				height;
	t_vector		x;
	t_vector		y;
	t_vector		z;
}	t_bump;

typedef struct s_plane
{
	t_vector		point;
	t_vector		normal;
	t_color			color;
	t_bump			bump;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	t_vector			point;
	t_vector			normal;
	float				diameter;
	float				height;
	t_color				color;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_cone
{
	t_vector			point;
	t_vector			normal;
	float				diameter;
	float				height;
	t_color				color;
	float				cos;
	struct s_cone		*next;
}	t_cone;

typedef struct s_rt
{
	t_amb_light	amb;
	t_camera	cam;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_cone		*cone;
	t_count		count;
}	t_rt;

#endif
