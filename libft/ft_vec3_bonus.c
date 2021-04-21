#include "libft_bonus.h"

t_vec3		*ft_vec3(double x, double y, double z)
{
	t_vec3	*a;

	a = (t_vec3 *)malloc(sizeof(t_vec3));
	(*a)[0] = x;
	(*a)[1] = y;
	(*a)[2] = z;
	(*a)[3] = 1.0;
	return (a);
}
