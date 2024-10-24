/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:08:07 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/24 17:35:20 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	cy_cap(t_cylinder cy, t_ray p_ray)
{
	t_p	c_c_top;
	t_p	c_c_bottom;
	int	top;
	int	bottom;

	c_c_top = get_c_c_top(cy);
	c_c_bottom = get_c_c_bottom(cy);
	top = cy_cap_hit(cy, p_ray, c_c_top);
	bottom = cy_cap_hit(cy, p_ray, c_c_bottom);
	if (top == 1 || bottom == 1)
		return (1);
	return (0);
}

int	cy_cap_hit(t_cylinder cy, t_ray p_ray, t_p c_c)
{
	t_v		pl_nv;
	t_plane	pl;
	double	t;
	t_p		val_p;

	pl_nv = v_norm(get_vec_two_points(c_c, cy.cy_origin));
	pl.n_vec = pl_nv;
	pl.op = c_c;
	t = get_plane_t(pl, p_ray);
	val_p = point_multi_vector(p_ray.ray_vector, t);
	if (distance(c_c, val_p) <= cy.cy_r)
		return (1);
	return (0);
}

t_p get_c_c_top(t_cylinder cy)
{
    t_p ret;

    ret.x = cy.cy_origin.x + ((cy.cy_height / 2) * cy.cy_nv.x);
    ret.y = cy.cy_origin.y + ((cy.cy_height / 2) * cy.cy_nv.y);
    ret.z = cy.cy_origin.z + ((cy.cy_height / 2) * cy.cy_nv.z);
    return (ret);
}

t_p get_c_c_bottom(t_cylinder cy)
{
	t_p	ret;

	ret.x = cy.cy_origin.x + ((cy.cy_height / 2) * (cy.cy_nv.x * -1));
	ret.y = cy.cy_origin.y + ((cy.cy_height / 2) * (cy.cy_nv.y * -1));
	ret.z = cy.cy_origin.z + ((cy.cy_height / 2) * (cy.cy_nv.z * -1));
	return (ret);
}

int	cylinder_hit(t_cylinder cy, t_ray p_ray, double *val1, double *val2)
{
	t_p		abc;
	double	disc;

	abc.x = get_cy_a(cy, p_ray);
	if (abc.x == 0)
		return (0);
	abc.y = get_cy_b(cy, p_ray);
	abc.z = get_cy_c(cy, p_ray);
	disc = pow(abc.y, 2) - 4 * abc.x * abc.z;
	if (disc < 0)
		return (0);
	*val1 = (-abc.y + sqrt(disc)) / (2 * abc.x);
	*val2 = (-abc.y - sqrt(disc)) / (2 * abc.x);
	if (*val1 < 0 && *val2 < 0)
		return (0);
	if (*val1 < 1e-6 && *val1 > -1e-6)
		*val1 = 0;
	if (*val2 < 1e-6 && *val2 > -1e-6)
		*val2 = 0;
	return (1);
}
