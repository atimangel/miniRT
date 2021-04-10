#include "libft_bonus.h"

double		ft_vec3_dot_product(t_vec3 v1, t_vec3 v2)
{
	double 	dot;
	int		i;

	i = 0;
	dot = 0.0;
	while (i < 3)
	{
		dot += v1.v[i] * v2.v[i];
		i++;
	}
	return (dot);
}
