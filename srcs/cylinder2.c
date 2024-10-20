/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:08:07 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/20 15:51:50 by woosupar         ###   ########.fr       */
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
	val_p = get_plane_val(p_ray, t);
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
	double	a;
	double	b;
	double	c;
	double	disc;

	a = get_cy_a(cy, p_ray);
	if (a == 0)
		return (0);
	b = get_cy_b(cy, p_ray);
	c = get_cy_c(cy, p_ray);
	disc = pow(b, 2) - 4 * a * c;
	if (disc > 0)
	{
		*val1 = ((-1 * b) + sqrt(disc)) / (2 * a);
		*val2 = ((-1 * b) - sqrt(disc)) / (2 * a);
		return (2);
	}
	if (disc == 0)
	{
		*val1 = (-1 * b) / (2 * a);
		*val2 = *val1;
		return (1);
	}
	else
		return (0);
}
