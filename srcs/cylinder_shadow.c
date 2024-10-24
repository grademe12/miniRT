/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_shadow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:36:00 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/24 21:41:15 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	cylinder_shadow(t_cylinder *cy, t_ray sh_ray, t_scene *scene)
{
	t_p		vals;
	t_p		p1;
	t_p		p2;

	if (cylinder_hit(*cy, sh_ray, &vals.x, &vals.y) == 0)
		return (0);
	p1 = point_multi_vector(sh_ray.ray_vector, vals.x);
	p2 = point_multi_vector(sh_ray.ray_vector, vals.y);
	if (cylinder_check(cy, sh_ray, scene, p1) == 0 && \
		cylinder_check(cy, sh_ray, scene, p2) == 0)
		return (0);
	if (cylinder_shadow2(cy, sh_ray, scene, vals))
		return (1);
	return (0);
}

int	cylinder_shadow2(t_cylinder *cy, t_ray sh_ray, t_scene *scene, t_p vals)
{
	double	min;
	double	max;
	t_p		min_p;
	t_p		max_p;

	min = double_min(vals.x, vals.y);
	min_p = point_multi_vector(sh_ray.ray_vector, min);
	max = double_max(vals.x, vals.y);
	max_p = point_multi_vector(sh_ray.ray_vector, max);
	if (vals.x > 0 && vals.y > 0)
	{
		if (distance(sh_ray.ray_point, scene->obj.val_p) <= 1e-5 && (distance\
		(sh_ray.ray_point,scene->light.origin) < distance(sh_ray.ray_point, \
		max_p)))
		if (distance(sh_ray.ray_point, min_p) > distance(sh_ray.ray_point, scene->light.origin))
			return (0);
		return (1);
	}
	if (min < 0)
		if (cylinder_check(cy, sh_ray, scene, max_p) && max_p.z > 0)
			return (1);
	if (max < 0)
		if (cylinder_check(cy, sh_ray, scene, min_p) && min_p.z > 0)
			return (1);
	return (0);
}
