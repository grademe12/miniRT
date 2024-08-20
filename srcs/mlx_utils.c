/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:05:46 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/21 02:27:35 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	save_distance(t_scene *scene, double tmp_dis, int type, t_p val)
{
	if (scene->obj.g_distance < 0)
	{
		scene->obj.g_distance = tmp_dis;
		scene->obj.type = type;
		scene->obj.val_p = val;
		return ;
	}
	if (scene->obj.g_distance > tmp_dis)
	{
		scene->obj.g_distance = tmp_dis;
		scene->obj.type = type;
		scene->obj.val_p = val;
	}
}
