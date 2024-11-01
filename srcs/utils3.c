/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:50:48 by woosupar          #+#    #+#             */
/*   Updated: 2024/11/02 00:26:07 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode == 53)
	{
		if (info->mlxdata->window)
			mlx_destroy_window(info->mlxdata->mlx, info->mlxdata->window);
		free(info->mlxdata->mlximg);
		free(info->scene->sp);
		free(info->scene->plane);
		free(info->scene->cy);
		free(info);
	}
	exit(0);
}

int	split_check(char c, char *str)
{
	char	*a;

	a = str;
	while (*a)
	{
		if (*a == c)
			return (1);
		a++;
	}
	return (0);
}

int	exit_rt(t_info *info)
{
	free(info->mlxdata->mlximg);
	free(info);
	free(info->scene->sp);
	free(info->scene->plane);
	free(info->scene->cy);
	mlx_destroy_window(info->mlxdata->mlx, info->mlxdata->window);
	exit(0);
}

void	mv_left_top(int x, int y, t_scene *scene)
{
	scene->cam.left_top.x = (x - 800 / 2.0) * (scene->vp.width / 800);
	scene->cam.left_top.y = (600 / 2.0 - y) * (scene->vp.height / 600);
	scene->cam.left_top.z = 50;
	// scene->cam.left_top.x = x - 800 / 2;
	// scene->cam.left_top.y = 600 / 2 - y;
}
