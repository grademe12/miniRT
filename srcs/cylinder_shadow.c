/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_shadow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:36:00 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/29 05:14:31 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	cylinder_shadow(t_cylinder *cy, t_ray sh_ray, t_scene *scene)
{
	t_cs		cs;
	double		min_dis;
	double		max_dis;

	cs.side_sol = p_build(sh_ray.o.x, sh_ray.o.y, sh_ray.o.z);
	cs.cap_sol = p_build(sh_ray.o.x, sh_ray.o.y, sh_ray.o.z);
	if (cylinder_hit(*cy, sh_ray, scene, &cs.side_sol) == 0 && \
		cy_cap(*cy, sh_ray, scene, &cs.cap_sol) == 0)
		return (0);
	cs.min_p = min_point(sh_ray.o, cs.side_sol, cs.cap_sol);
	cs.max_p = max_point(sh_ray.o, cs.side_sol, cs.cap_sol);
	min_dis = dis(sh_ray.o, cs.min_p);
	max_dis = dis(sh_ray.o, cs.max_p);
	if (min_dis == 0 && max_dis <= 1e-5)
		return (0);
	if (min_dis > 0 && min_dis <= 1e-5 && \
	(max_dis > dis(sh_ray.o, scene->li.o)))
		return (0);
	if (min_dis > 1e-5 && (min_dis > dis(sh_ray.o, scene->li.o)))
		return (0);
	if (max_dis > dis(sh_ray.o, scene->li.o))
		return (0);
	return (1);
}

t_p	min_point(t_p origin, t_p x, t_p y)
{
	if (dis(origin, x) >= dis(origin, y))
		return (y);
	return (x);
}

t_p	max_point(t_p origin, t_p x, t_p y)
{
	if (dis(origin, x) >= dis(origin, y))
		return (x);
	return (y);
}
