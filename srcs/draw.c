/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:53:58 by woosupar          #+#    #+#             */
/*   Updated: 2024/11/03 17:49:48 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	draw_rt(t_mlxdata *mlxdata, t_scene *scene)
{
	mlxdata->mlximg->addr = mlx_get_data_addr(mlxdata->mlximg->img, \
	&mlxdata->mlximg->bit_per_pixel, &mlxdata->mlximg->line_len, \
	&mlxdata->mlximg->endian);
	do_pixel(mlxdata, scene);
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->window, \
	mlxdata->mlximg->img, 0, 0);
}

void	my_mlx_pixel_put(t_mlximg *mlximg, int x, int y, int color)
{
	char	*dst;

	dst = mlximg->addr + (y * mlximg->line_len + x * \
		(mlximg->bit_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	do_pixel(t_mlxdata *mlxdata, t_scene *scene)
{
	t_color	pixel;
	int		color;
	double	x_idx;
	double	y_idx;

	y_idx = 0;
	while (y_idx < 600)
	{
		x_idx = 0;
		while (x_idx < 800)
		{
			mv_left_top(x_idx, y_idx, scene);
			scene->obj.g_distance = -1;
			scene->obj.flag = 1;
			scene->obj.inside_flag = 0;
			shoot_ray(scene, &pixel);
			color = trgb(0, (int)pixel.r, (int)pixel.g, (int)pixel.b);
			my_mlx_pixel_put(mlxdata->mlximg, x_idx, y_idx, color);
			x_idx++;
		}
		y_idx++;
	}
}

void	shoot_ray(t_scene *scene, t_color *pixel)
{
	t_ray		p_ray;
	t_obj		tmp;

	p_ray.o = scene->cam.camera_point;
	p_ray.v = get_vec(p_ray.o, scene->cam.left_top);
	p_ray.v = v_norm(p_ray.v);
	shoot_sphere(scene, p_ray);
	shoot_plane(scene, p_ray);
	shoot_cylinder(scene, p_ray);
	tmp.type = scene->obj.type;
	tmp.val_p = scene->obj.val_p;
	tmp.ptr = scene->obj.ptr;
	tmp.g_distance = scene->obj.g_distance;
	scene->obj.flag = 0;
	if (scene->obj.g_distance == -1)
	{
		pixel_nothing(pixel);
		return ;
	}
	if (object_shadow(scene))
		pixel_shadow(pixel, tmp, scene);
	else
		pixel_light(pixel, tmp, scene);
}
