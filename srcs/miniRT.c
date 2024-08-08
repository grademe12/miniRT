/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:48:02 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/08 21:22:45 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int main()
{
    t_camera	*cam;
	t_viewport	*vp;
	t_sphere	*sp;

	cam = (t_camera *)malloc(sizeof(t_camera));
	vp = (t_viewport *)malloc(sizeof(t_viewport));
	sp = (t_sphere *)malloc(sizeof(t_sphere));
	cam->camera_point.x = 0;
	cam->camera_point.y = 0;
	cam->camera_point.z = 0;
	cam->ctv_norm.x = 0;
	cam->ctv_norm.y = 0;
	cam->ctv_norm.z = 1;
	cam->viewport_h = 500;
	cam->viewport_w = 500;
	vp->height = 500;
	vp->width = 500;
	sp->sp_origin.x = 400;
	sp->sp_origin.y = 400;
	sp->sp_origin.z = 5000;
	sp->sp_r = 100;

	get_vp_left_top(cam, vp);
	double	x_idx;
	double	y_idx;
	// double	r;
	// double	g;
	// double	b;

	x_idx = 0;
	y_idx = 0;
	t_ray	ray;

	ray.ray_point.x = 0;
	ray.ray_point.y = 0;
	ray.ray_point.z = 0;
	int		val;
	printf ("P3\n%d %d\n255\n", vp->width, vp->height);
	while (y_idx < 500)
	{	
		x_idx = 0;
		while (x_idx < 500)
		{
			ray.ray_vector = get_vec_two_points(ray.ray_point, cam->left_top);
			ray.ray_vector = v_norm(ray.ray_vector);
			val = sphere(sp, &ray);
			if (val >= 1)
				printf ("%d %d %d\n", 255, 255, 255);
			else
				printf ("%d %d %d\n", 128, 128, 128);
			cam->left_top.x++;
			x_idx++;
		}
		cam->left_top.x = cam->left_top.x - cam->viewport_w;
		cam->left_top.y--;
		y_idx++;
	}
	
    return (0);
}

t_color	get_rgb(t_scene scene)
{
	t_color	ret;
	double	x_idx;
	double	y_idx;

	y_idx = 0;
	while (y_idx < scene.vp.height)
	{
		x_idx = 0;
		while (x_idx < scene.vp.width)
		{
			
		}
	}
}
