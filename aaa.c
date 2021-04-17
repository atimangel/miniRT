#include <stdlib.h>
#include <stdio.h>

void	ft_a(int *q)
{
	q = (int *)malloc(sizeof(int));
	*q = 1;
}
int	main(void)
{
	int a;

	ft_a(&a);
	printf("%d\n" ,a);
	free(&a);
}
