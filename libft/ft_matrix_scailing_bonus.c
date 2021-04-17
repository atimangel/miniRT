#include "libft_bonus.h"

t_a16	*ft_matrix_scailing(double x, double y, double z)
{
	t_a16	*scala;

	scala = ft_matrix_identity();
	if (!scala)
		return (0);
	(*scala)[0][0] = x;
	(*scala)[1][1] = y;
	(*scala)[2][2] = z;
	return (scala);
}
