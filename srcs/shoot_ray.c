/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:43:07 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/23 17:39:37 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	shoot_plane(t_scene *scene, t_ray p_ray)
{
	t_plane	*pl;
	int		ret;

	pl = scene->plane;
	while (pl != 0)
	{
		ret = plane(pl, scene, p_ray);
		pl++;
	}
	return (ret);
}

int	shoot_cylinder(t_scene *scene, t_ray p_ray)
{
	t_cylinder	*cy;
	int			ret;

	cy = scene->cy;
	while (cy != 0)
	{
		ret = cylinder(cy, p_ray, scene);
		cy++;
	}
	return (ret);
}

int	shoot_sphere(t_scene *scene, t_ray p_ray)
{
	t_sphere	*sp;
	int			ret;

	sp = scene->sp;
	while (sp != 0)
	{
		ret = sphere(sp, p_ray, scene);
		sp++;
	}
	return (ret);
}