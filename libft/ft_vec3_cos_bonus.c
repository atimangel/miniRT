#include "libft_bonus.h"

double		ft_vec3_cos(t_vec3 v1, t_vec3 v2)
{
	double cos;

	cos = ft_vec3_dot_product(v1, v2) / (ft_vec3_len(v1) * ft_vec3_len(v2));
	return (cos);
}
