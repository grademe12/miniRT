/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:33:49 by woosupar          #+#    #+#             */
/*   Updated: 2024/11/03 16:53:23 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	define_side_sol(t_scene *scene, t_ray p_ray, t_p vals, t_p *sol)
{
	if (vals.x * vals.y < 0 && scene->obj.flag == 1)
		scene->obj.inside_flag = 1;
	if (vals.x * vals.y > 0)
		*sol = get_p(p_ray.o, p_ray.v, fmin(vals.x, vals.y));
	else if (vals.x * vals.y < 0)
		*sol = get_p(p_ray.o, p_ray.v, fmax(vals.x, vals.y));
	else if (vals.x * vals.y == 0)
		*sol = get_p(p_ray.o, p_ray.v, fmax(vals.x, vals.y));
	return (1);
}

int	cylinder_rad(t_scene *scene, t_cylinder *cy)
{
	t_v		to_light;
	t_p		point;
	t_v		radiul;
	double	rad_dis;
	double	height_proj;

	if (cylinder_check(cy, scene->li.o, scene) == 0)
		return (0);
	to_light = get_vec(scene->li.o, cy->cy_origin);
	height_proj = v_dot(to_light, cy->cy_nv);
	point = get_p(cy->cy_origin, cy->cy_nv, height_proj);
	radiul = get_vec(scene->li.o, point);
	rad_dis = v_len(radiul);
	if (rad_dis <= cy->cy_r)
		return (1);
	return (0);
}

int	cylinder_hit(t_cylinder cy, t_ray p_ray, t_scene *scene, t_p *sol)
{
	t_p		abc;
	t_p		vals;
	double	disc;

	abc.x = get_cy_a(cy, p_ray);
	if (abc.x == 0)
		return (0);
	abc.y = get_cy_b(cy, p_ray);
	abc.z = get_cy_c(cy, p_ray);
	disc = pow(abc.y, 2) - 4 * abc.x * abc.z;
	vals.x = (-abc.y + sqrt(disc)) / (2 * abc.x);
	vals.y = (-abc.y - sqrt(disc)) / (2 * abc.x);
	if (fabs(vals.x) <= 1e-5)
		vals.x = 0;
	if (fabs(vals.y) <= 1e-5)
		vals.y = 0;
	if (disc < 0 || (vals.x <= 0 && vals.y <= 0))
		return (0);
	if (define_side_sol(scene, p_ray, vals, sol) == 0)
		return (0);
	if (cylinder_check(&cy, *sol, scene) == 0)
		return (0);
	return (1);
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

	p = get_vec(cy.cy_origin, p_ray.o);
	ret = 2 * (v_dot(p_ray.v, p) - (v_dot(p_ray.v, \
				cy.cy_nv) * v_dot(p, cy.cy_nv)));
	return (ret);
}
