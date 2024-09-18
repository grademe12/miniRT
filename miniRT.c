/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:48:02 by woosupar          #+#    #+#             */
/*   Updated: 2024/09/19 00:47:29 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "openGL/mlx.h"

int main(int argc, char *argv[])
{
	t_info		info;
	t_scene		scene;
	t_mlxdata	mlxdata;
	

	if (argc != 2)
		error_print("Invalid argument");
	if (name_valid(argv[1]) == 1)
		error_print("Invalid file name");
	init_info(&info, &scene, &mlxdata);
	parse(argv[1], &info);
	// mlx = mlx_init();
	// window = mlx_new_window(mlx, scene.cam->viewport_w, scene.cam->viewport_h, "Ray");
	// mlxdata = (t_mlxdata *)malloc(sizeof(t_mlxdata));
	// mlxdata->mlx = mlx;
	// mlxdata->window = window;
	// draw_rt(mlxdata, scene);
	// mlx_loop(mlx);
}
