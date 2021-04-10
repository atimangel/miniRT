/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.ke>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 10:45:14 by snpark            #+#    #+#             */
/*   Updated: 2020/12/28 14:58:19 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_BONUS_H
# define _LIBFT_BONUS_H

# include <math.h>
/*
**Bonus MiniRT ARRAY & VECTOR
*/
/*
**Vector
*/
typedef struct s_vector3
{
	double v[4];
}				t_vec3;

double	ft_vec3_len(t_vec3 v);
t_vec3	ft_vec3_normalize(t_vec3 v);
t_vec3	ft_vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3	ft_vec3_remove(t_vec3 v1, t_vec3 v2);
t_vec3	ft_vec3_scale(t_vec3 v, double scala);
double	ft_vec3_dot_product(t_vec3 v1, t_vec3 v2);
double	ft_vec3_cos(t_vec3 v1, t_vec3 v2);
t_vec3	ft_vec3_cross_product(t_vec3 v1, t_vec3 v2);
//vec3transformcoord 변환된 벡터를 얻어주는 함수vector는 4개의 성분으로 (x,y,z,1)이다. 좌표 평행이동을 허용한다.
//vec3transformnomal (x, y, z, 0)으로 좌표 평행이동을 금지한다.
/*
**Array
*/
typedef struct s_array16
{
	double	a[4][4];
}				t_a16;

double		ft_matrix_determinant(t_a16 array);
t_a16		ft_matrix_identity(void);
t_a16		ft_matrix_transpose(t_a16 array);
t_a16		ft_matrix_inverse(t_a16 array, double determinant);
t_a16		ft_matrix_translation(t_a16 *array, double x, double y, double z);
t_a16		ft_matrix_rotation_x(t_a16 array, double radian);
t_a16		ft_matrix_rotation_y(t_a16 array, double radian);
t_a16		ft_matrix_rotation_z(t_a16 array, double radian);
t_a16		ft_matrix_scailing(t_a16 array, double x, double y, double z);
#endif
