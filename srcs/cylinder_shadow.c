/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_shadow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:36:00 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/24 00:57:54 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	cylinder_shadow(t_cylinder *cy, t_ray sh_ray, t_scene *scene)
{
	t_p		vals;

	if (cylinder_hit(*cy, sh_ray, &vals.x, &vals.y) == 0)
		return (0);
	if (cylinder_shadow2(cy, sh_ray, scene, vals))
		return (1);
	return (0);
}

int	cylinder_shadow2(t_cylinder *cy, t_ray sh_ray, t_scene *scene, t_p vals)
{
	double	min;
	// double	max;
	t_p		min_p;
	// t_p		max_p;

	min = double_min(vals.x, vals.y);
	min_p = point_multi_vector(sh_ray.ray_vector, min);
	if (vals.x * vals.y > 0)
	{
		if (cylinder_check(cy, sh_ray, scene, min_p) && distance(min_p, sh_ray.ray_point) < 1e-6)
			return (0);
	}
	return (1);
}
