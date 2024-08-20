/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:43:07 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/21 02:45:47 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	shoot_plane(t_scene *scene, t_ray p_ray)
{
	t_plane	*pl_ptr;
	int		ret;

	pl_ptr = scene->plane;
	while (pl_ptr != 0)
	{
		ret = plane(scene, p_ray);
		pl_ptr++;
	}
	return (ret);
}

int	shoot_cylinder(t_scene *scene, t_ray p_ray)
{
	t_cylinder	*cy;
	double		val1;
	double		val2;

	cy = scene->cy;
	while (cy != 0)
	{
		cylinder(scene, p_ray, &val1, &val2);
		cy++;
	}
	return (0);
}

int	shoot_sphere(t_scene *scene, t_ray p_ray)
{
	t_sphere	*sp;

	sp = scene->sp;
	while (sp != 0)
	{
		sphere(sp, p_ray, )
	}
}