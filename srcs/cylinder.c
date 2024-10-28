/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:38:28 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/29 04:49:16 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

// int	cylinder(t_cylinder *cy, t_ray p_ray, t_scene *scene)
// {
// 	int		hit;
// 	double	val1;
// 	double	val2;
// 	t_p		rend_p;

// 	hit = cylinder_hit(*cy, p_ray, &val1, &val2);
// 	if (hit == 0)
// 		return (0);
// 	if (val1 * val2 < 0)
// 		scene->obj.inside_flag = 1;
// 	if (val1 * val2 > 0 && val1 >= val2)
// 		rend_p = point_multi_vector(p_ray.ray_vector, val2);
// 	else if (val1 * val2 > 0 && val1 < val2)
// 		rend_p = point_multi_vector(p_ray.ray_vector, val1);
// 	else if (val1 * val2 < 0 && val1 >= val2)
// 		rend_p = point_multi_vector(p_ray.ray_vector, val1);
// 	else if (val1 * val2 < 0 && val1 < val2)
// 		rend_p = point_multi_vector(p_ray.ray_vector, val2);
// 	if (hit > 0 && cylinder_check(cy, p_ray, scene, rend_p))
// 		return (1);
// 	return (0);
// }

int	cylinder(t_cylinder *cy_, t_ray p_ray, t_scene *scene)
{
	t_cs	cs;
	int		side_hit;
	int		cap_hit;
	void	*ptr;

	cs.side_sol = p_build(0, 0, 0);
	cs.cap_sol = p_build(0, 0, 0);
	side_hit = cylinder_hit(*cy_, p_ray, scene, &cs.side_sol);
	cap_hit = cy_cap(*cy_, p_ray, scene, &cs.cap_sol);
	if (side_hit == 0 && cap_hit == 0)
		return (0);
	if (side_hit == 0)
		cs.rend_p = cs.cap_sol;
	if (cap_hit == 0)
		cs.rend_p = cs.side_sol;
	if (side_hit != 0 && (dis(p_ray.o, cs.side_sol) <= dis(p_ray.o, cs.cap_sol)))
		cs.rend_p = cs.side_sol;
	if (cap_hit != 0 && (dis(p_ray.o, cs.side_sol) > dis(p_ray.o, cs.cap_sol)))
		cs.rend_p = cs.cap_sol;
	if (dis(p_ray.o, cs.rend_p) == 0)
		return (0);
	ptr = cy_;
	save_distance(scene, cy, cs.rend_p, ptr);
	return (1);
}

int	cylinder_check(t_cylinder *cy_p, t_p rend_p)
{
	double	comp;
	t_v		rend_p_v;
	double	range;

	rend_p_v = get_vec_two_points(rend_p, cy_p->cy_origin);
	comp = v_dot(rend_p_v, cy_p->cy_nv);
	range = (cy_p->cy_height / 2) + 1e-6;
	if (comp <= range && comp >= range * -1)
		return (1);
	return (0);
}

double	get_cy_a(t_cylinder cy, t_ray p_ray)
{
	double	ret;

	ret = 1 - pow(v_dot(cy.cy_nv, p_ray.v), 2);
	return (ret);
}

double	get_cy_b(t_cylinder cy, t_ray p_ray)
{
	double	ret;
	t_v		p;

	p = get_vec_two_points(cy.cy_origin, p_ray.o);
	ret = 2 * (v_dot(p_ray.v, p) - (v_dot(p_ray.v, \
				cy.cy_nv) * v_dot(p, cy.cy_nv)));
	return (ret);
}

double	get_cy_c(t_cylinder cy, t_ray p_ray)
{
	double	ret;
	t_v		p;

	p = get_vec_two_points(cy.cy_origin, p_ray.o);
	ret = pow(v_len(p), 2) - pow(v_dot(p, cy.cy_nv), 2) - pow(cy.cy_r, 2);
	return (ret);
}
