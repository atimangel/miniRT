#include "libft_bonus.h"

void	ft_puta16(t_a16 array)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		printf("{");
		while (j < 4)
		{
			printf("%f ", array[i][j]);
			j++;
		}
		printf("}\n");
		i++;
	}
}
