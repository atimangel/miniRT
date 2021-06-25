#include "minirt.h"

void	ft_save_bmp()
{
	char	file_header[14];
	char	info_header[40];
	char	*pixel_data;
	char	*bitmapfile;
	t_resolution	*res;

	res = ft_find_obj(obj, R, 0);
	ft_memcpy(file_header, "BM", 2);
	ft_memcpy(file_header + 2, 54 + res->x * res->y * 32, 4);
	ft_memset(file_header + 6, 0, 4);
	ft_memcpy(file_header + 10, 54, 4)
	ft_memcpy(info_header, 40, 4);
	ft_memcpy(info_header + 4, res->x, 4);
	ft_memcpy(info_header + 8, res->y, 4);
	ft_memcpy(info_header + 10, 1, 2);
	ft_memcpy(info_header + 12, 24, 2);
	ft_memcpy(info_header + 14, 0, 4);
}
