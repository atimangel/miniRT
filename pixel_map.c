#include "minirt.h"
#include <stdio.h>

t_image_plane	*ft_make_image_plane(t_resolution res, t_camera cam)
{
	t_image_plane	*ip;
	t_vec3		*tmp;
	t_vec3		*abs_up;

	ip = (t_image_plane *)malloc(sizeof(t_image_plane));
	if (!ip)
		printf("error\nmalloc error make_image_plane\n");
	abs_up = ft_vec3(0.0, 1.0, 0.0);
	tmp = ft_vec3_cross_product(cam.direction, *abs_up);
	ft_memcpy(&ip->right, tmp, sizeof(t_vec3));
	free(tmp);
	tmp = ft_vec3_cross_product(cam.direction, ip->right);
	ft_memcpy(&ip->up, tmp, sizeof(t_vec3));
	free(tmp);
	ip->len_h = 2 * tan(M_PI * (cam.fov / 180) / 2);
	ip->fov_v = (res.y * cam.fov) / res.x;
	ip->len_v = ip->len_h * res.y / res.x;
	free(abs_up);
	return (ip);
}

t_vec3	*ft_trans_image_plane(t_pixel_unit *u, t_image_plane ip, t_resolution res, t_camera cam)
{
	t_vec3	*pixel_r;
	t_vec3	*pixel_u;
	t_vec3	*pixel_p;
	t_vec3	*tmp;

	pixel_r = ft_vec3_scale(ip.right, (u->x + 0.5 - res.x / 2.0) / res.x * ip.len_h);
	pixel_u = ft_vec3_scale(ip.up, (u->y + 0.5 - res.y / 2.0) / res.y  * ip.len_v);
	pixel_p = ft_vec3_add(cam.camera, *pixel_r);
	tmp = pixel_p;
	pixel_p = ft_vec3_add(*pixel_p, *pixel_u);
	free(tmp);
	tmp = pixel_p;
	pixel_p = ft_vec3_add(*pixel_p, cam.direction);
	free(tmp);
	free(pixel_u);
	free(pixel_r);
	return (pixel_p);
}

void	ft_make_pixel_map(t_mlx mlx, t_pixel_map *pm, t_resolution res)
{
	pm->img_ptr = mlx_new_image(mlx.ptr, res.x, res.y);
	pm->pixel_str = mlx_get_data_addr(pm->img_ptr, &pm->bpp, &pm->l_len, &pm->endian);
}

void	ft_reset(t_pixel_unit *u, t_ray *r)
{
	u->p_r = 0x00;
	u->p_g = 0x00;
	u->p_b = 0x00;
	r->t = -1.0;
	u->o_n = 0;
}
void	ft_draw_pixel_map(t_pixel_map pm, t_list *obj, t_resolution res, t_camera cam)
{
	t_pixel_unit	u;
	t_image_plane	*ip;
	t_ray			r;
	void		*touched;

	ip = ft_make_image_plane(res, cam);
	ft_memcpy(&r.e, &cam.camera, sizeof(t_vec3));
	u.x = 0;
	while (u.x < res.x)
	{
		u.y = 0;
		while (u.y < res.y)
		{
			ft_reset(&u, &r);
			r.d = ft_trans_image_plane(&u, *ip, res, cam);
			touched = ft_touch(&r, &u, obj, 0);
			if (r.t != -1.0)
			{
				ft_ambient_reflection(&u, obj);
				ft_reflection(r, &u, obj, touched);
				ft_light_max(&u);
				free(u.o_n);
			}
			free(r.d);
			*(unsigned int *)(pm.pixel_str + pm.l_len * u.y + pm.bpp * u.x / 8) = (u.p_r << 16) + (u.p_g << 8) + u.p_b;
			u.y++;
		}
		u.x++;
	}
	free(ip);
}
