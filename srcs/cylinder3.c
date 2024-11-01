/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:32:41 by woosupar          #+#    #+#             */
/*   Updated: 2024/11/01 19:08:41 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	get_cy_side_t(t_cylinder *cy, t_p val_p)
{
	double	ret;
	t_v		vec;

	vec.x = val_p.x - cy->cy_origin.x;
	vec.y = val_p.y - cy->cy_origin.y;
	vec.z = val_p.z - cy->cy_origin.z;
	ret = v_dot(vec, cy->cy_nv);
	return (ret);
}

t_v	get_cy_normal(t_cylinder *cy, t_p val_p)
{
	t_p	c_c_top;
	t_p	c_c_bottom;

	c_c_top = get_c_c_top(*cy);
	c_c_bottom = get_c_c_bottom(*cy);
	if (plane_check(cy->cy_nv, c_c_top, val_p))
		return (v_mul(cy->cy_nv, -1));
	if (plane_check(cy->cy_nv, c_c_bottom, val_p))
		return (cy->cy_nv);
	return (cy_side_normal(cy, val_p));
}

t_v	cy_side_normal(t_cylinder *cy, t_p val_p)
{
	t_v		ret;
	t_p		npoa;
	double	t;

	t = get_cy_side_t(cy, val_p);
	npoa = get_p(cy->cy_origin, cy->cy_nv, t);
	ret = get_vec(val_p, npoa);
	return (v_norm(ret));
}
