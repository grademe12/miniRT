/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:05:46 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/31 18:03:28 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	save_distance(t_scene *scene, int type, t_p val, void *ptr)
{
	double	tmp;

	if (scene->obj.flag == 0)
	{
		save_shadow_distance(scene, type, val, ptr);
		return ;
	}
	tmp = dis(scene->cam.camera_point, val);
	if (scene->obj.g_distance < 0)
	{
		scene->obj.g_distance = tmp;
		scene->obj.type = type;
		scene->obj.val_p = p_build(val.x, val.y, val.z);
		scene->obj.ptr = ptr;
		return ;
	}
	if (scene->obj.g_distance > tmp)
	{
		scene->obj.g_distance = tmp;
		scene->obj.type = type;
		scene->obj.val_p = val;
		scene->obj.ptr = ptr;
	}
}

void	save_shadow_distance(t_scene *scene, int type, t_p val, void *ptr)
{
	double	tmp;

	if (scene->obj.flag == 1)
		return ;
	tmp = dis(scene->obj.val_p, val);
	if (scene->sh_obj.g_distance < 0)
	{
		scene->sh_obj.g_distance = tmp;
		scene->sh_obj.type = type;
		scene->sh_obj.val_p = p_build(val.x, val.y, val.z);
		scene->sh_obj.ptr = ptr;
		return ;
	}
	if (scene->sh_obj.g_distance > tmp)
	{
		scene->sh_obj.g_distance = tmp;
		scene->sh_obj.type = type;
		scene->sh_obj.val_p = p_build(val.x, val.y, val.z);
		scene->sh_obj.ptr = ptr;
	}
}
