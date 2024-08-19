/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:48:02 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/19 18:20:18 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "openGL/mlx.h"

int main()
{
    t_camera	*cam;
	t_viewport	*vp;
	t_sphere	*sp;
	t_amb		amb;
	t_light		light;
	t_scene		scene;
	t_plane		pl;
	t_cylinder	cy;

	cam = (t_camera *)malloc(sizeof(t_camera));
	vp = (t_viewport *)malloc(sizeof(t_viewport));
	sp = (t_sphere *)malloc(sizeof(t_sphere));
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
	sp->sp_origin.z = 1000;
	sp->sp_r = 200;
	amb.a_color.r = 255;
	amb.a_color.g = 255;
	amb.a_color.b = 255;
	amb.ratio = 0.2;
	light.origin.x = -500;
	light.origin.y = 300;
	light.origin.z = 1000;
	light.ratio = 7;
	scene.amb = amb;
	scene.cam = cam;
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
	cy.cy_height = 400;
	cy.cy_origin.x = 0;
	cy.cy_origin.y = 0;
	cy.cy_origin.z = 1000;
	cy.cy_r = 200;
	cy.cy_nv.x = 0;
	cy.cy_nv.y = 10;
	cy.cy_nv.z = 0;
	cy.cy_nv = v_norm(cy.cy_nv);
	scene.cy = &cy;
	
	get_vp_left_top(cam, vp);
	void		*mlx;
	void		*window;
	t_mlxdata	*mlxdata;

	mlx = mlx_init();
	window = mlx_new_window(mlx, scene.cam->viewport_w, scene.cam->viewport_h, "Ray");
	mlxdata = (t_mlxdata *)malloc(sizeof(t_mlxdata));
	mlxdata->mlx = mlx;
	mlxdata->window = window;
	draw_rt(mlxdata, scene);
	mlx_loop(mlx);
}
