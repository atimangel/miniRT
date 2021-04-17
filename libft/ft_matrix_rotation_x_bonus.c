#include "libft_bonus.h"

t_a16	*ft_matrix_rotation_x(double radian)
{
	t_a16	*ro_x;

	ro_x = ft_matrix_identity();
	if (!ro_x)
		return(0);
	(*ro_x)[1][1] = cos(radian);
	(*ro_x)[2][2] = cos(radian);
	(*ro_x)[1][2] = -1 * sin(radian);
	(*ro_x)[2][1] = sin(radian);
	return (ro_x);	
}
