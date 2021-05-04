#include "minirt.h"

void	*ft_make_square(char *line)
{
	t_square	*s;
	t_vec3		*normal;

	s = (t_square *)malloc(sizeof(t_square));
	if (!s)
		printf("error\nmalloc error square.c\n");
	line += 2;
	s->id = sq;
	line = ft_pass_space(line);
	line = ft_read_vec3(line, s->center);
	line = ft_pass_space(line);
	line = ft_read_vec3(line, s->normal);
	line = ft_pass_space(line);
	line = ft_read_float(line, &s->len, 0);
	line = ft_pass_space(line);
	line = ft_read_char(line, &s->red, 1);
	line = ft_read_char(line, &s->green, 1);
	line = ft_read_char(line, &s->blue, 0);
	line = ft_pass_space(line);
	if (*line != '\0')
		printf("error\nstring is not end null character square.c\n");
	if (ft_vec3_len(s->normal) != 1.0)
	{
		normal = ft_vec3_normalize(s->normal);
		ft_memcpy(&s->normal, normal, sizeof(t_vec3));
		free(normal);
	}
	ft_putvec(s->center);
	ft_putvec(s->normal);
	return (s);
}
void	ft_square_touch(t_ray *r, t_pixel_unit *u)
{
/*	t_square	sq;
	t_vec3		*abs_up;
	t_vec3		*up;
	t_vec3		*right;
	t_vec3		*tmp;
	t_vec3		*v3;
	t_vec3		*v4;
	t_a16		*m;
	t_a16		*m_inverse;
	double		beta;
	double		gamma;
	double		t;

//	ft_make_square(&sq);
	abs_up = ft_vec3(0.0, 1.0, 0.0);
	right = ft_vec3_cross_product(*sq.normal, *abs_up);
	up = ft_vec3_cross_product(*sq.normal, *right);
	tmp = right;
	right = ft_vec3_normalize(*right);
	free(tmp);
	tmp = up;
	up = ft_vec3_normalize(*up);
	free(tmp);
	v3 = ft_vec3_remove(*sq.center, *r->e);
	m = ft_matrix(*up, *right, *r->d);
	m_inverse = ft_matrix_inverse(*m, ft_matrix_determinant(*m));
	v4 = ft_vec3_transform_normal(*m_inverse, *v3);
	beta = (*v4)[0];
	gamma = (*v4)[1];
	t = (*v4)[2];
	if ((beta >= sq.len / -2 && beta <= sq.len / 2) && (gamma >= sq.len / -2 && gamma <= sq.len / 2))
	{
		if((r->t > 0 & t < r->t) || (r->t <= 0))
		{
			u->o_r = sq.red;
			u->o_g = sq.green;
			u->o_b = sq.blue;
			if (u->o_n != 0)
				free(u->o_n);
			if (ft_vec3_dot_product(*r->d, *sq.normal) < 0)
				u->o_n = sq.normal;
			else if (ft_vec3_dot_product(*r->d, *sq.normal) > 0)
				u->o_n = ft_vec3_scale(*sq.normal, -1);
			r->t = t;
			printf("sq normal ");
			ft_putvec(*sq.normal);
		}
	}
	if (u->o_n != sq.normal)
		free(sq.normal);
	free(abs_up);
	free(up);
	free(right);
	free(v3);
	free(v4);
	free(m);
	free(m_inverse);*/
}
