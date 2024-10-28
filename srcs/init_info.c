/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:47:59 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/29 00:38:21 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	init_info(t_info *info, t_scene *scene, t_mlxdata *mlxdata)
{
	info->scene = scene;
	info->mlxdata = mlxdata;
	scene->sp = NULL;
	scene->plane = NULL;
	scene->cy = NULL;
	scene->amb.flag = 0;
	scene->li.flag = 0;
	scene->cam.flag = 0;
	init_mlxdata(info->mlxdata);
}

void	init_mlxdata(t_mlxdata *mlxdata)
{
	mlxdata->mlx = mlx_init();
	mlxdata->window = mlx_new_window(mlxdata->mlx, 800, 600, "Ray");
	mlxdata->mlximg = (t_mlximg *)malloc(sizeof(t_mlximg));
	mlxdata->mlximg->img = mlx_new_image(mlxdata->mlx, 800, 600);
}

void	init_scene(t_scene *scene)
{
	scene->vp.width = 2 * tan((scene->cam.fov / 2) * (M_PI / 180.0)) * 100;
	scene->vp.height = scene->vp.width * ((float)600 / 800);
}
