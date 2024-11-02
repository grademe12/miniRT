/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:38:28 by woosupar          #+#    #+#             */
/*   Updated: 2024/11/02 22:55:31 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	cylinder(t_cylinder *cy_, t_ray p_ray, t_scene *scene)
{
	t_cs	cs;
	void	*ptr;
	int		inside;

	cs.ss = p_build(0, 0, 0);
	cs.cs = p_build(0, 0, 0);
	inside = 0;
	cylinder_hit(*cy_, p_ray, scene, &cs.ss);
	if (scene->obj.inside_flag == 1)
		inside = 1;
	cy_cap(*cy_, p_ray, scene, &cs.cs);
	cs.cs_dis = dis(p_ray.o, cs.cs);
	cs.ss_dis = dis(p_ray.o, cs.ss);
	if (define_cs_p(&cs) == 0)
		return (0);
	if (dis(cs.p, p_ray.o) == 0)
		return (0);
	scene->obj.inside_flag |= inside;
	ptr = cy_;
	save_distance(scene, cy, cs.p, ptr);
	return (1);
}

int	define_cs_p(t_cs *cs)
{
	if (cs->cs_dis == 0 && cs->ss_dis == 0)
		return (0);
	if (cs->ss_dis != 0 && cs->cs_dis >= cs->ss_dis)
		cs->p = cs->ss;
	if (cs->cs_dis != 0 && cs->cs_dis < cs->ss_dis)
		cs->p = cs->cs;
	if (cs->cs_dis == 0)
		cs->p = cs->ss;
	if (cs->ss_dis == 0)
		cs->p = cs->cs;
	return (1);
}

int	cylinder_check(t_cylinder *cy_p, t_p rend_p, t_scene *scene)
{
	double	comp;
	t_v		rend_p_v;
	double	range;

	rend_p_v = get_vec(rend_p, cy_p->cy_origin);
	comp = v_dot(rend_p_v, cy_p->cy_nv);
	range = (cy_p->cy_height / 2) + 1e-6;
	if (comp <= range && comp >= range * -1)
		return (1);
	if (scene->obj.flag == 1)
		scene->obj.inside_flag = 0;
	return (0);
}

double	get_cy_c(t_cylinder cy, t_ray p_ray)
{
	double	ret;
	t_v		p;

	p = get_vec(cy.cy_origin, p_ray.o);
	ret = pow(v_len(p), 2) - pow(v_dot(p, cy.cy_nv), 2) - pow(cy.cy_r, 2);
	return (ret);
}
