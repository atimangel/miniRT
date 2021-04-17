#include "libft_bonus.h"

t_a16		*ft_matrix_translation(t_a16 a, double x, double y, double z)
{
	t_a16	*translate;

	translate = ft_matrix_identity();
	if(!translate)
		return (0);
	(*translate)[0][3] = x;
	(*translate)[1][3] = y;
	(*translate)[2][3] = z;
	return (translate);
}
