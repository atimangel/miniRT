#include "minirt.h"

void	*ft_make_resolution(char *line)
{
	t_resolution *res;

	res = (t_resolution *)malloc(sizeof(t_resolution));
	line += 1;
	while (*line == ' ')
		line++;
	if (ft_isdigit(*line))
		res->x = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ')
		line++;
	if (ft_isdigit(*line))
		res->y = ft_atoi(line);
	while (*line == ' ' || *line != '\0')
		line++;
	if (*line != '\0')
		printf("error\n wtf? %c\n", *line);
	res->id = R;
	return (res);
}
