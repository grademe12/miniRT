/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:38:28 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/23 17:52:01 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	cylinder(t_cylinder *cy, t_ray p_ray, t_scene *scene)
{
	int		hit;
	double	val1;
	double	val2;
	t_p		rend_p;

	hit = cylinder_hit(*cy, p_ray, &val1, &val2);
	if (val1 >= val2)
		rend_p = point_multi_vector(p_ray.ray_vector, val2);
	else
		rend_p = point_multi_vector(p_ray.ray_vector, val1);
	if (hit >= 1)
	{
		if (cylinder_check(cy, p_ray, scene, rend_p))
			return (1);
	}
	return (0);
}

int	cylinder_check(t_cylinder *cy_p, t_ray p_ray, t_scene *scene, t_p rend_p)
{
	double	comp;
	t_v		rend_p_v;
	void	*ptr;

	rend_p_v = get_vec_two_points(rend_p, cy_p->cy_origin);
	comp = v_dot(rend_p_v, cy_p->cy_nv);
	ptr = cy_p;
	if (comp <= cy_p->cy_height && comp >= -1 * cy_p->cy_height)
	{
		save_distance(scene, cy, rend_p, ptr);
		return (1);
	}
	if (cy_cap(*cy_p, p_ray))
	{
		save_distance(scene, cy, rend_p, ptr);
		return (1);
	}
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
