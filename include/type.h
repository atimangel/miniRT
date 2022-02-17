/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:50:45 by snpark            #+#    #+#             */
/*   Updated: 2022/02/16 11:18:31 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef	union	u_color
{
	struct
	{
		int	r;
		int	g;
		int	b;
	};
	int		color[3];
}	t_color;

typedef	union u_vector
{
	struct
	{
		double	x;
		double	y;
		double	z;
	};
	double		coordinate[3];
}	t_vector;

typedef	struct	s_amb_light
{
	double	ratio;	
	t_color	color;
}	t_amb_light;

typedef	struct	s_camera
{
	t_vector	view_point;
	t_vector	normalized_oriention_vector;
	double		horizontal_field_of_view;
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
	double			ratio;
	t_color			color;
	struct s_light	*next;
}	t_light;

typedef struct s_sphere
{
	t_vector		point;
	double			diameter;
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
	double				diameter;
	double				height;
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
}	t_rt;

#endif
