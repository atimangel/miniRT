#include "libft_bonus.h"

double		ft_vec3_len(t_vec3 v)
{
	double len;

	len = 0;
	len = pow(v.v[0], 2.0) + pow(v.v[1], 2.0) + pow(v.v[2], 2.0);
	len = sqrt(len);
	return (len);
}
