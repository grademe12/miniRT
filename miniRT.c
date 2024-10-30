/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:48:02 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/30 15:00:11 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char *argv[])
{
	t_info		*info;
	t_scene		scene;
	t_mlxdata	mlxdata;

	if (argc != 2)
		error_print("Invalid argument");
	info = (t_info *)malloc(sizeof(t_info));
	if (name_valid(argv[1]) == 1)
		error_print("Invalid file name");
	init_info(info, &scene, &mlxdata);
	parse(argv[1], info);
	init_scene(&scene);
	move_object(&scene);
	rotate_object(&scene);
	int i = 1;
	t_cylinder *cur_cy;
	t_plane *cur_pl;
	t_sphere *cur_sp;
	cur_cy = scene.cy;
	while (cur_cy != 0)
	{
		printf ("%d번째 원기둥\n", i);
		printf ("원기둥 원점 : %f %f %f\n", cur_cy->cy_origin.x, cur_cy->cy_origin.y, cur_cy->cy_origin.z);
		printf ("원기둥 벡터 : %f %f %f\n", cur_cy->cy_nv.x, cur_cy->cy_nv.y, cur_cy->cy_nv.z);
		printf ("============================================================\n");
		cur_cy = cur_cy->next;
		i++;
	}
	cur_pl = scene.plane;
	i = 1;
	while (cur_pl != 0)
	{
		printf ("%d번째 평면\n", i);
		printf ("평면 원점 : %f %f %f\n", cur_pl->op.x, cur_pl->op.y, cur_pl->op.z);
		printf ("평면 벡터 : %f %f %f\n", cur_pl->n_vec.x, cur_pl->n_vec.y, cur_pl->n_vec.z);
		printf ("============================================================\n");
		cur_pl = cur_pl->next;
		i++;
	}
	i = 1;
	cur_sp = scene.sp;
	while (cur_sp != 0)
	{
		printf ("%d번째 구\n", i);
		printf ("구 원점 : %f %f %f\n", cur_sp->sp_origin.x, cur_sp->sp_origin.y, cur_sp->sp_origin.z);
		printf ("=============================================================\n");
		cur_sp = cur_sp->next;
		i++;
	}
	draw_rt(info->mlxdata, info->scene);
	mlx_key_hook(info->mlxdata->window, key_hook, info);
	mlx_hook(info->mlxdata->window, 17, 0, exit_rt, info);
	mlx_loop(info->mlxdata->mlx);
	return (0);
}
