/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:50:45 by snpark            #+#    #+#             */
/*   Updated: 2022/02/18 20:56:08 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct	s_count
{
	t_bool	ambient;
	t_bool	camera;
	int		light;
	int		sphere;
	int		plane;
	int		cylinder;
}	t_count;

typedef	union	u_color
{
	struct
	{
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;
	};
	int		color[4];
}	t_color;

typedef	union u_vector
{
	struct
	{
		float	x;
		float	y;
		float	z;
	};
	float		coordinate[3];
}	t_vector;

typedef	struct	s_amb_light
{
	float	ratio;	
	t_color	color;
}	t_amb_light;

typedef	struct	s_camera
{
	t_vector	view_point;
	t_vector	normalized_oriention_vector;
	float		horizontal_field_of_view;
}	t_camera;

typedef	struct	s_len
{
	int	light;
	int	sphere;
	int	plane;
	int	cylineer;
}	t_len;

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
	struct s_phere	*next;
}	t_sphere;

typedef struct	s_plane
{
	t_vector		point;
	t_vector		normalized_orientation_vector;
	t_color			color;
	struct s_plane	*next;
}	t_plane;

typedef struct	s_cylinder
{
	t_vector			point;
	t_vector			normalized_orientation_vector;
	float				diameter;
	float				height;
	t_color				color;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_rt
{
	t_amb_light	amb;
	t_camera	cam;
	t_len		len;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_count		count;
}	t_rt;

#endif
