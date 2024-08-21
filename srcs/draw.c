/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:53:58 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/21 20:58:23 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	draw_rt(t_mlxdata *mlxdata, t_scene *scene)
{
	mlxdata->mlximg->img = mlx_new_image(mlxdata->mlx, scene->cam->viewport_w, \
	scene->cam->viewport_h);
	mlxdata->mlximg->addr = mlx_get_data_addr(mlxdata->mlximg, &mlxdata->mlximg \
	->bit_per_pixel, &mlxdata->mlximg->line_len, &mlxdata->mlximg->endian);
	do_pixel(mlxdata, scene);
}

void	my_mlx_pixel_put(t_mlximg *mlximg, int x, int y, int color)
{
	char	*dst;

	dst = mlximg->addr + (y * mlximg->line_len + x * (mlximg->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	do_pixel(t_mlxdata *mlxdata, t_scene *scene)
{
	t_color	*pixel;
	int		color;
	double	x_idx;
	double	y_idx;

	y_idx = 0;
	while (y_idx < scene->vp.height)
	{
		x_idx = 0;
		while (x_idx < scene->vp.width)
		{
			shoot_ray(scene, pixel);
			color = trgb(0, (int)pixel->r, (int)pixel->g, (int)pixel->b);
			my_mlx_pixel_put(mlxdata->mlximg, x_idx, y_idx, color);
			x_idx++;
			scene->obj.g_distance = -1;
		}
		scene->cam->left_top.x -= scene->cam->viewport_w;
		y_idx++;
	}
}

void	shoot_ray(t_scene *scene, t_color *pixel)
{
	t_ray		p_ray;

	scene->cam->camera_point.x++;
	scene->cam->camera_point.y--;
	p_ray.ray_point = scene->cam->camera_point;
	p_ray.ray_vector = get_vec_two_points(p_ray.ray_point, scene->cam->left_top);
	p_ray.ray_vector = v_norm(p_ray.ray_vector);
	shoot_plane(scene, p_ray);
	shoot_cylinder(scene, p_ray);
	shoot_sphere(scene, p_ray);
	if (object_shadow(scene))
		pixel_shadow(pixel);
	else
		pixel_light(pixel);
}
