#include "libft_bonus.h"

t_a16	*ft_matrix_rotation_z(double radian)
{
	t_a16	*ro_z;

	ro_z = ft_matrix_identity();
	if (!ro_z)
		return (0);
	(*ro_z)[0][0] = cos(radian);
	(*ro_z)[1][1] = cos(radian);
	(*ro_z)[0][1] = -1 * sin(radian);
	(*ro_z)[1][0] = sin(radian);
	return (ro_z);
}
