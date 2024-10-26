/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_shadow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:36:00 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/26 22:19:33 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	cylinder_shadow(t_cylinder *cy, t_ray sh_ray, t_scene *scene)
{
	t_sol	sol;
	t_p		vals;

	if (cylinder_hit(*cy, sh_ray, &vals.x, &vals.y) == 0)
		return (0);
	sol.max = double_max(vals.x, vals.y);
	sol.min = double_min(vals.x, vals.y);
	sol.max_p = get_p(sh_ray.ray_point, sh_ray.ray_vector, sol.max);
	sol.min_p = get_p(sh_ray.ray_point, sh_ray.ray_vector, sol.min);
	if (cylinder_check(cy, sh_ray, scene, sol.max_p) == 0 && \
		cylinder_check(cy, sh_ray, scene, sol.min_p) == 0)
		return (0);
	if (cylinder_shadow2(cy, sh_ray, scene, sol))
		return (1);
	return (0);
}

int	cylinder_shadow2(t_cylinder *cy, t_ray sh_ray, t_scene *scene, t_sol sol)
{
	if (sol.min > 0 && sol.max > 0)
	{
		if (distance(sh_ray.ray_point, scene->obj.val_p) <= 1e-5 && (distance \
		(sh_ray.ray_point, scene->light.origin) < distance(sh_ray.ray_point, \
		sol.max_p)) && distance(sh_ray.ray_point, sol.min_p) <= 1e-5)
			return (0);
		if (distance(sh_ray.ray_point, sol.min_p) > distance(sh_ray.ray_point, \
		scene->light.origin))
			return (0);
		return (1);
	}
	if (sol.min < 0)
		if (cylinder_check(cy, sh_ray, scene, sol.max_p) && sol.max_p.z > 0)
			return (1);
	if (sol.max < 0)
		if (cylinder_check(cy, sh_ray, scene, sol.min_p) && sol.min_p.z > 0)
			return (1);
	return (0);
}
