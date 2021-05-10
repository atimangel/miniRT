#include "minirt.h"

void	*ft_make_triangle(char *line)
{
	t_triangle	*t;

	t = (t_triangle *)malloc(sizeof(t_triangle));
	if (!t)
		printf("error\nmalloc error triangl.c\n");
	line += 2;
	line = ft_pass_space(line);
	line = ft_read_vec3(line, t->point_1);
	line = ft_pass_space(line);
	line = ft_read_vec3(line, t->point_2);
	line = ft_pass_space(line);
	line = ft_read_vec3(line, t->point_3);
	line = ft_pass_space(line);
	line = ft_read_char(line, &t->red, 1);
	line = ft_read_char(line, &t->green, 1);
	line = ft_read_char(line, &t->blue, 0);
	line = ft_pass_space(line);
	if (*line != '\0')
		printf("error\nstring is not end null character triangle.c\n");
	return (t);
}

t_vec3	*ft_triangle_interaction(t_triangle tr, t_ray *r, t_vec3 **n)
{
	t_vec3	*side1;
	t_vec3	*side2;
	t_vec3	*v1;
	t_a16	*m;
	t_a16	*m_inverse;
	t_vec3	*tmp;

	side1 = ft_vec3_remove(tr.point_1, tr.point_2);
	side2 = ft_vec3_remove(tr.point_1, tr.point_3);
	*n = ft_vec3_cross_product(*side1, *side2);
	if (ft_vec3_dot_product(**n, *r->d) > 0)
	{
		tmp = *n;
		*n = ft_vec3_scale(*tmp, -1);
		free(tmp);
	}
	v1 = ft_vec3_remove(tr.point_1, r->e);
	m = ft_matrix(*side1, *side2, *r->d);
	m_inverse = ft_matrix_inverse(*m, ft_matrix_determinant(*m));
	free(side1);
	free(side2);
	free(m);
	side1 = ft_vec3_transform_normal(*m_inverse, *v1);
	free(m_inverse);
	free(v1);
	return (side1);
}

void	ft_triangle_touch(t_ray *r, t_pixel_unit *u, void *obj, char flag)
{
	t_triangle	*tr;
	double		t;
	t_vec3		*v;
	t_vec3		*n;

	tr = obj;
	v = ft_triangle_interaction(*tr, r, &n);
	t = (*v)[2];
	if (t != -1.0 && ((*v)[0] >= 0 && (*v)[0] <= 1) && ((*v)[1] >= 0 && (*v)[1] <= 1)
			&& ((*v)[0] + (*v)[1] <= 1) && ft_vec3_dot_product(*n, *r->d) != 0 && ft_isclose(r->t, t))
	{
		r->t = t;
		if (flag == 0)
		{
			ft_putcolor(u, tr->red, tr->green, tr->blue);
			if (u->o_n != 0)
				free(u->o_n);
			u->o_n = n;
		}
	}
	if (u->o_n != n)
		free(n);
	free(v);
}
