/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:32:41 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/22 02:09:52 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	get_cy_side_t(t_cylinder *cy, t_p val_p)
{
	double	ret;

	ret = (((val_p.x - cy->cy_origin.x) * cy->cy_nv.x) + \
			((val_p.y - cy->cy_origin.y) * cy->cy_nv.y) + \
			((val_p.z - cy->cy_origin.z) * cy->cy_nv.z));
	return (ret);
}

int	cylinder_shadow(t_cylinder *cy, t_ray ray, t_scene *scene, double val)
{
	t_p	rend_p;

	if (val < 0)
		return (0);
	rend_p = point_multi_vector(ray.ray_vector, val);
	if (cylinder_check(cy, ray, scene, rend_p) && (distance(rend_p, ray.ray_point) < \
	distance(ray.ray_point, scene->light.origin)))
		return (1);
	return (0);
}