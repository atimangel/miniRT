#include "minirt.h"

void	*ft_make_resolution(char *line)
{
	t_resolution *res;

	res = (t_resolution *)malloc(sizeof(t_resolution));
	line += 1;
	line = ft_pass_space(line);
	if (ft_isdigit(*line))
		res->x = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line = ft_pass_space(line);
	if (ft_isdigit(*line))
		res->y = ft_atoi(line);
	line = ft_pass_space(line);
	if (*line != '\0')
		printf("error\n string is not end null character\n");
	res->id = R;
	return (res);
}
