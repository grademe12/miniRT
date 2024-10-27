/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:33:49 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/27 22:06:31 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	define_side_sol(t_scene *scene, t_ray p_ray, t_p vals, t_p *sol)
{
	if (vals.x * vals.y < 0 && scene->obj.flag == 1)
		scene->obj.inside_flag = 1;
	if (vals.x * vals.y > 0 && vals.x >= vals.y && fabs(vals.y) > 1e-6)
		*sol = get_p(p_ray.ray_point, p_ray.ray_vector, vals.y);
	if (vals.x * vals.y > 0 && vals.x >= vals.y && fabs(vals.y) <= 1e-6)
		*sol = get_p(p_ray.ray_point, p_ray.ray_vector, vals.x);
	if (vals.x * vals.y > 0 && vals.x < vals.y && fabs(vals.x) > 1e-6)
		*sol = point_multi_vector(p_ray.ray_vector, vals.x);
	if (vals.x * vals.y > 0 && vals.x < vals.y && fabs(vals.x) <= 1e-6)
		*sol = get_p(p_ray.ray_point, p_ray.ray_vector, vals.y);
	if (vals.x * vals.y < 0 && vals.x >= vals.y)
		*sol = point_multi_vector(p_ray.ray_vector, vals.x);
	if (vals.x * vals.y < 0 && vals.x < vals.y)
		*sol = point_multi_vector(p_ray.ray_vector, vals.y);
	return (1);
}
