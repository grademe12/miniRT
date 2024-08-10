/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:48:02 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/10 18:54:55 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int main()
{
    t_camera	*cam;
	t_viewport	*vp;
	t_sphere	*sp;
	t_amb		amb;
	t_light		light;
	t_scene		scene;

	cam = (t_camera *)malloc(sizeof(t_camera));
	vp = (t_viewport *)malloc(sizeof(t_viewport));
	sp = (t_sphere *)malloc(sizeof(t_sphere));
	cam->camera_point.x = 0;
	cam->camera_point.y = 0;
	cam->camera_point.z = 0;
	cam->ctv_norm.x = 0;
	cam->ctv_norm.y = 0;
	cam->ctv_norm.z = 1000;
	cam->viewport_h = 500;
	cam->viewport_w = 500;
	vp->height = 500;
	vp->width = 500;
	sp->sp_origin.x = 400;
	sp->sp_origin.y = 400;
	sp->sp_origin.z = 5000;
	sp->sp_r = 100;
	amb.a_color.r = 255;
	amb.a_color.g = 255;
	amb.a_color.b = 255;
	amb.ratio = 0.2;
	light.origin.x = -400;
	light.origin.y = 400;
	light.origin.z = 5000;
	light.ratio = 0.6;
	scene.amb = amb;
	scene.cam = *cam;
	scene.sp = sp;
	scene.light = light;
	scene.vp = *vp;

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
	double	*val1;
	double	*val2;
	t_p		val1_p;
	t_p		val2_p;
	t_p		rend_p;
	double	coef;
	val1 = (double *)malloc(sizeof(double));
	val2 = (double *)malloc(sizeof(double));
	printf ("P3\n%d %d\n255\n", vp->width, vp->height);
	while (y_idx < 500)
	{	
		x_idx = 0;
		while (x_idx < 500)
		{
			ray.ray_vector = get_vec_two_points(ray.ray_point, cam->left_top);
			// ray.ray_vector = v_norm(ray.ray_vector);
			val = sphere(sp, &ray, val1, val2);
			if (val == 1)
				printf ("%d %d %d\n", 255, 255, 255);
			else if (val == 2)
			{
				val1_p.x = *val1 * cam->left_top.x;
				val1_p.y = *val1 * cam->left_top.y;
				val1_p.z = *val1 * cam->left_top.z;
				val2_p.x = *val2 * cam->left_top.x;
				val2_p.y = *val2 * cam->left_top.y;
				val2_p.z = *val2 * cam->left_top.z;
				if (distance(cam->camera_point, val1_p) > distance(cam->camera_point, val2_p))
					rend_p = val2_p;
				else
					rend_p = val1_p;
				coef = get_light_coef(amb, scene, rend_p);
				printf ("%d %d %d\n", (int)(255 * coef), (int)(255 * coef), (int)(255 * coef));
			}
			else
				printf ("%d %d %d\n", 225, 225, 225);
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
