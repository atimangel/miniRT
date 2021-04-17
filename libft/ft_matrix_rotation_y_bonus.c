#include "libft_bonus.h"

t_a16		*ft_matrix_rotation_y(double radian)
{
	t_a16	*ro_y;

	ro_y = ft_matrix_identity();
	if (!ro_y)
		return (0);
	(*ro_y)[0][0] = cos(radian);
	(*ro_y)[2][2] = cos(radian);
	(*ro_y)[0][2] = -1 * sin(radian);
	(*ro_y)[2][0] = sin(radian);
	return (ro_y);
}
