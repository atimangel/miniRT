#include "libft_bonus.h"

t_a16	*ft_matrix_transpose(t_a16 a)
{
	t_a16	*trans;
	int		i;
	int		j;

	trans = (t_a16 *)malloc(sizeof(t_a16));
	if(!trans)
		return (0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*trans)[i][j] = a[j][i];
			j++;
		}
		i++;
	}
	return (trans);
}
