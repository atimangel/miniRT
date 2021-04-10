#include <mlx.h>
#include <stdio.h>
typedef struct s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
}	t_image;

typedef	struct s_pixel {
	double r;
	double g;
	double b;
}			t_pixel;

int	main(void)
{
	void	*connect;
	void	*window;
	t_image	img;
	t_pixel pix;	
	int		i;
	int		j;
	int		height;
	int		width;
	int		color;

	height = 1000;
	width = 1000;
	connect = mlx_init();
	window = mlx_new_window(connect, height, width, "ppm");
	img.img = mlx_new_image(connect, height, width);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_len, &img.endian);
	j = height - 1;
	while (j >= 0)
	{
		i = width - 1;
		while (i >= 0)
		{
			color = 0;
			pix.r = (double)i / (width - 1);
			pix.g = (double)j / (height - 1);
			pix.b = 0.25;
			color += (int)(255.999 * pix.r) << 16;
			color += (int)(255.999 * pix.g) << 8;
			color += (int)(255.999 * pix.b);
			printf("(%d,%d) = %x\n", i, j, color);
			*(unsigned int *)(img.addr + (img.l_len * j) + (img.bpp * i / 8)) = color;
			i--;
		}
		j--;
	}
	mlx_put_image_to_window(connect, window, img.img, 0, 0);
	mlx_loop(connect);
}
