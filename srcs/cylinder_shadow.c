/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_shadow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:36:00 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/27 22:55:42 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

// int	cylinder_shadow(t_cylinder *cy, t_ray sh_ray, t_scene *scene)
// {
// 	t_sol	sol;
// 	t_p		side_sol;
// 	t_p		cap_sol;
// 	t_p		vals;

// 	if (cylinder_hit(*cy, sh_ray, scene, &side_sol) == 0 && \
// 		cy_cap(*cy, sh_ray, scene, &cap_sol) == 0)
// 		return (0);
// 	sol.max = double_max(vals.x, vals.y);
// 	sol.min = double_min(vals.x, vals.y);
// 	sol.max_p = get_p(sh_ray.ray_point, sh_ray.ray_vector, sol.max);
// 	sol.min_p = get_p(sh_ray.ray_point, sh_ray.ray_vector, sol.min);
// 	if (cylinder_check(cy, sh_ray, scene, sol.max_p) == 0 && \
// 		cylinder_check(cy, sh_ray, scene, sol.min_p) == 0)
// 		return (0);
// 	if (cylinder_shadow2(cy, sh_ray, scene, sol))
// 		return (1);
// 	return (0);
// }

int	cylinder_shadow(t_cylinder *cy, t_ray sh_ray, t_scene *scene)
{
	t_p		side_sol;
	t_p		cap_sol;
	t_p		min_p;
	t_p		max_p;
	
	if (cylinder_hit(*cy, sh_ray, scene, &side_sol) == 0 && \
		cy_cap(*cy, sh_ray, scene, &cap_sol) == 0)
		return (0);
	min_p = min_point(sh_ray.ray_point, side_sol, cap_sol);
	max_p = max_point(sh_ray.ray_point, side_sol, cap_sol);
	if (fabs(distance(sh_ray.ray_point, min_p)) <= 1e-5 && \
	(distance(sh_ray.ray_point, max_p) > distance(sh_ray.ray_point, scene->light.origin)))
		return (0);
	//캡 맞았을때, 광원과 거리 비교 해야함
	// 사이드도 마찬가지.
	return (1);
}

t_p	min_point(t_p origin, t_p x, t_p y)
{
	if (distance(origin, x) >= distance(origin, y))
		return (y);
	return (x);
}

t_p	max_point(t_p origin, t_p x, t_p y)
{
	if (distance(origin, x) >= distance(origin, y))
		return (x);
	return (y);
}

// int	cylinder_shadow2(t_cylinder *cy, t_ray sh_ray, t_scene *scene, t_sol sol)
// {
// 	if (sol.min > 0 && sol.max > 0)
// 	{
// 		if (distance(sh_ray.ray_point, scene->obj.val_p) <= 1e-5 && (distance \
// 		(sh_ray.ray_point, scene->light.origin) < distance(sh_ray.ray_point, \
// 		sol.max_p)) && distance(sh_ray.ray_point, sol.min_p) <= 1e-5)
// 			return (0);
// 		if (distance(sh_ray.ray_point, sol.min_p) > distance(sh_ray.ray_point, \
// 		scene->light.origin))
// 			return (0);
// 		return (1);
// 	}
// 	if (scene->cam.left_top.x == 0 && scene->cam.left_top.y == 0)
// 		printf ("min max : %f %f\n", sol.min, sol.max);
// 	if (sol.min < 0 && cylinder_check(cy, sh_ray, scene, sol.max_p) && \
// 	(distance(sh_ray.ray_point, sol.max_p) < distance(sh_ray.ray_point, \
// 	scene->light.origin)))
// 		return (1);
// 	return (0);
// }
