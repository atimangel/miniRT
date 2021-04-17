#include "libft_bonus.h"

void	ft_putvec(t_vec3 vec)
{
	int	i;

	i = 0;
	printf("{");
	while (i < 4)
	{
		printf("%f ", vec[i]);
		i++; 
	}
	printf("}\n");
}
