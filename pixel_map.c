#include "minirt.h"
#include <stdio.h>

typedef struct s_image_plane
{
	t_vec3	*camera;
	t_vec3	*direction;
	double	fob_h;
	double	fob_v;
	t_vec3	*abs_up;
	t_vec3	*right;
	t_vec3	*up;
	double	len_h;
	double	len_v;
	int		x;
	int		y;
}		t_image_plane;

void	ft_free_image_plane(t_image_plane *ip)
{
	free(ip->camera);
	free(ip->direction);
	free(ip->abs_up);
	free(ip->right);
	free(ip->up);
}

void	ft_make_image_plane(t_image_plane *ip)
{
	t_vec3	*tmp;

	ip->x = 500;
	ip->y = 500;
	ip->camera = ft_vec3(0.0, 0.0, -1.0);
	ip->direction = ft_vec3(0.0, 0.0, -1.0);
	ip->fob_h = 120;
	ip->abs_up = ft_vec3(0.0, 1.0, 0.0);
	ip->right = ft_vec3_cross_product(*ip->direction, *ip->abs_up);
	ip->up = ft_vec3_cross_product(*ip->direction, *ip->right);
	tmp = ip->right;
	ip->right = ft_vec3_normalize(*ip->right);
	free(tmp);
	tmp = ip->up;
	ip->up = ft_vec3_normalize(*ip->up);
	free(tmp);
	ip->len_h = 2 * tan(M_PI * (ip->fob_h / 180) / 2);
	ip->fob_v = (ip->y * ip->fob_h) / ip->x;
	ip->len_v = 2 * tan(M_PI * (ip->fob_v / 180) / 2);
/*	printf("fob_h %f fob_v %f len_h %f len_v%f x %d y %d\n", ip->fob_h, ip->fob_v, ip->len_h, ip->len_v, ip->x, ip->y);
	printf("tan(30) = %f\n" , tan(M_PI * (30 / 360)));
	printf("camera, direction, right, up\n");
	ft_putvec(*ip->camera);
	ft_putvec(*ip->direction);
	ft_putvec(*ip->right);
	ft_putvec(*ip->up);*/
}

t_vec3	*ft_trans_image_plane(t_pixel_unit *u, t_image_plane ip)
{
	t_vec3	*pixel_r;
	t_vec3	*pixel_u;
	t_vec3	*pixel_p;
	t_vec3	*tmp;

	pixel_r = ft_vec3_scale(*ip.right, (u->x + 0.5 - ip.x / 2.0) / ip.x * ip.len_h);//x == 500 u->x[0,499] [-249.5,249.5]
	pixel_u = ft_vec3_scale(*ip.up, (u->y + 0.5 - ip.y / 2.0) / ip.y  * ip.len_v);
	pixel_p = ft_vec3_add(*ip.camera, *pixel_r);
	tmp = pixel_p;
	pixel_p = ft_vec3_add(*pixel_p, *pixel_u);
	free(tmp);
	tmp = pixel_p;
	pixel_p = ft_vec3_add(*pixel_p, *ip.direction);
	free(tmp);
	free(pixel_u);
	free(pixel_r);
//	printf("(%d, %d) => ", u->x, u->y);
//	ft_putvec(*pixel_p);
	return (pixel_p);
}

void	ft_make_pixel_map(t_mlx mlx, t_pixel_map *pm)
{
	pm->img_ptr = mlx_new_image(mlx.ptr, 500, 500);
	pm->pixel_str = mlx_get_data_addr(pm->img_ptr, &pm->bpp, &pm->l_len, &pm->endian);
}

void	ft_draw_pixel_map(t_mlx mlx, t_pixel_map pm)
{
	t_pixel_unit	u;
	t_image_plane	ip;
	t_ray			r;

	u.x = 0;
	u.color = 0xf9f9ff;
	ft_make_image_plane(&ip);
	r.e = ip.camera;
	r.t_max = 50;
	while (u.x < 500)
	{
		u.y = 0;
		while (u.y < 500)
		{
			u.color = 0xf9f9ff;
			r.t = -1.0;
			r.d = ft_trans_image_plane(&u, ip);
			ft_sphere_touch(&r, &u.color);
			//ft_plane_touch(&r, &u.color);
			free(r.d);
			*(unsigned int *)(pm.pixel_str + pm.l_len * u.y + pm.bpp * u.x / 8) = u.color;
			u.y++;
		}
		u.x++;
	}
	mlx_put_image_to_window(mlx.ptr, mlx.win, pm.img_ptr, 0, 0);
	ft_free_image_plane(&ip);
}
