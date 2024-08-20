/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:38:28 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/20 22:01:16 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	cylinder(t_scene *scene, t_ray p_ray, double *val1, double *val2)
{
	int	hit;
	t_p	val1_p;
	t_p	val2_p;

	hit = cylinder_hit(*scene, p_ray, val1, val2);
	val1_p = point_multi_vector(p_ray.ray_vector, *val1);
	val2_p = point_multi_vector(p_ray.ray_vector, *val2);
	if (hit >= 1)
	{
		if (cylinder_check(scene, val1_p, val2_p, p_ray))
			return (1);
	}
	return (0);
}

int	cylinder_check(t_scene *scene, t_p val1_p, t_p val2_p, t_ray p_ray)
{
	double	comp;
	t_p		rend_p;
	t_v		rend_p_v;

	if (distance(scene->cam->camera_point, val1_p) >= distance(scene->cam->camera_point, val2_p))
		rend_p = val2_p;
	else
		rend_p = val1_p;
	rend_p_v = get_vec_two_points(rend_p, scene->cy->cy_origin);
	comp = v_dot(rend_p_v, scene->cy->cy_nv);
	if (comp <= scene->cy->cy_height && comp >= -1 * scene->cy->cy_height)
			return (1);
	if (cy_cap(*scene->cy, p_ray))
		return (1);
	return (0);
}

double	get_cy_a(t_cylinder cy, t_ray p_ray) // 모든 벡터가 정규화 되었다고 가정
{
	double	ret;

	ret = 1 - pow(v_dot(cy.cy_nv, p_ray.ray_vector), 2);
	return (ret);
}

double	get_cy_b(t_cylinder cy, t_ray p_ray)
{
	double	ret;
	t_v		p;

	p = get_vec_two_points(p_ray.ray_point, cy.cy_origin);
	ret = (2 * (v_dot(p_ray.ray_vector, p)) - (v_dot(p_ray.ray_vector, cy.cy_nv) * v_dot(p, cy.cy_nv)));
	return (ret);
}

double	get_cy_c(t_cylinder cy, t_ray p_ray)
{
	double	ret;
	t_v		p;

	p = get_vec_two_points(p_ray.ray_point, cy.cy_origin);
	ret = pow(v_len(p), 2) - pow(v_dot(p, cy.cy_nv), 2) - pow(cy.cy_r, 2);
	return (ret);
}
