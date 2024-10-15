/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:48:02 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/15 19:43:45 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main(int argc, char *argv[])
{
	t_info		info;
	t_scene		scene;
	t_mlxdata	*mlxdata;
	
	if (argc != 2)
		error_print("Invalid argument");
	if (name_valid(argv[1]) == 1)
		error_print("Invalid file name");
	mlxdata = (t_mlxdata *)malloc(sizeof(mlxdata));
	init_info(&info, &scene, mlxdata);
	parse(argv[1], &info);
	// mlx = mlx_init();
	// window = mlx_new_window(mlx, scene.cam->viewport_w, scene.cam->viewport_h, "Ray");
	// mlxdata = (t_mlxdata *)malloc(sizeof(t_mlxdata));
	// mlxdata->mlx = mlx;
	// mlxdata->window = window;
	draw_rt(info.mlxdata, info.scene);
	mlx_loop(info.mlxdata->mlx);
}
