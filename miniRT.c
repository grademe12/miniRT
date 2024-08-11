/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:48:02 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/11 21:54:10 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main()
{
    t_camera	*cam;
	t_viewport	*vp;
	t_sphere	*sp;
	t_amb		amb;
	t_light		light;
	t_scene		scene;
	t_plane		pl;

	cam = (t_camera *)malloc(sizeof(t_camera));
	vp = (t_viewport *)malloc(sizeof(t_viewport));
	sp = (t_sphere *)malloc(sizeof(t_sphere));
	// sp2 = (t_sphere *)malloc(sizeof(t_sphere));
	cam->camera_point.x = 0;
	cam->camera_point.y = 0;
	cam->camera_point.z = 0;
	cam->ctv_norm.x = 0;
	cam->ctv_norm.y = 0;
	cam->ctv_norm.z = 500;
	cam->viewport_h = 1080;
	cam->viewport_w = 1920;
	vp->height = 1080;
	vp->width = 1920;
	sp->sp_origin.x = 0;
	sp->sp_origin.y = 100;
	sp->sp_origin.z = 700;
	sp->sp_r = 200;
	amb.a_color.r = 255;
	amb.a_color.g = 255;
	amb.a_color.b = 255;
	amb.ratio = 0.2;
	light.origin.x = -500;
	light.origin.y = 300;
	light.origin.z = 200;
	light.ratio = 7;
	scene.amb = amb;
	scene.cam = *cam;
	scene.light = light;
	scene.vp = *vp;
	scene.sp = sp;
	pl.n_vec.x = 0;
	pl.n_vec.y = 1;
	pl.n_vec.z = 0;
	pl.op.x = 0;
	pl.op.y = -100;
	pl.op.z = 0;
	scene.plane = &pl;

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
	int		pl_val;
	double	*val1;
	double	*val2;
	t_p		val1_p;
	t_p		val2_p;
	t_p		rend_p;
	double	coef;
	val1 = (double *)malloc(sizeof(double));
	val2 = (double *)malloc(sizeof(double));
	printf ("P3\n%d %d\n255\n", vp->width, vp->height);
	while (y_idx < vp->height)
	{	
		x_idx = 0;
		while (x_idx < vp->width)
		{
			ray.ray_vector = get_vec_two_points(ray.ray_point, cam->left_top);
			// ray.ray_vector = v_norm(ray.ray_vector);
			val = sphere(sp, &ray, val1, val2);
			if (val >= 1)
			{
				val1_p.x = *val1 * cam->left_top.x;
				val1_p.y = *val1 * cam->left_top.y;
				val1_p.z = *val1 * cam->left_top.z;
				val2_p.x = *val2 * cam->left_top.x;
				val2_p.y = *val2 * cam->left_top.y;
				val2_p.z = *val2 * cam->left_top.z;
				if (distance(cam->camera_point, val1_p) >= distance(cam->camera_point, val2_p))
					rend_p = val2_p;
				else
					rend_p = val1_p;
				if (object_shadow(scene, rend_p) != 0)
					printf ("%d %d %d\n", 0, 0, 0);
				else
				{
					coef = get_light_coef(amb, scene, rend_p);
					printf ("%d %d %d\n", (int)(50 * coef), (int)(50 * coef), (int)(255 * coef));
				}
			}
			else if (val == 0)
			{
				pl_val = plane(scene, ray);
				if (pl_val == 1)
					printf ("%d %d %d\n", 125, 255, 0);
				else
					printf ("%d %d %d\n", 230, 230, 250);
			}
			cam->left_top.x++;
			x_idx++;
		}
		cam->left_top.x = cam->left_top.x - cam->viewport_w;
		cam->left_top.y--;
		y_idx++;
	}
	
    return (0);
}

// t_color	get_rgb(t_scene scene, double vp_x, double vp_y)
// {
// 	t_color	ret;

	
// }
