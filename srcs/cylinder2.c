/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:08:07 by woosupar          #+#    #+#             */
/*   Updated: 2024/11/03 17:48:03 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	cy_cap(t_cylinder cy, t_ray p_ray, t_scene *scene, t_p *val)
{
	t_sol	sol;

	if (cy_cap_hit(scene, cy, p_ray, &sol.vals) == 0)
		return (0);
	if (sol.vals.x * sol.vals.y > 0)
		*val = get_p(p_ray.o, p_ray.v, fmin(sol.vals.x, sol.vals.y));
	else if (sol.vals.x * sol.vals.y <= 0)
		*val = get_p(p_ray.o, p_ray.v, fmax(sol.vals.x, sol.vals.y));
	return (1);
}

int	cy_cap_hit(t_scene *scene, t_cylinder cy, t_ray p_ray, t_p *vals)
{
	t_p	top;
	t_p	bot;
	t_p	top_center;
	t_p	bot_center;

	top_center = get_p(cy.cy_origin, cy.cy_nv, cy.cy_height / 2);
	bot_center = get_p(cy.cy_origin, v_mul(cy.cy_nv, -1), cy.cy_height / 2);
	get_plane_val(cy, p_ray, &vals->x, cy.cy_nv);
	top = get_p(p_ray.o, p_ray.v, vals->x);
	get_plane_val(cy, p_ray, &vals->y, v_mul(cy.cy_nv, -1));
	bot = get_p(p_ray.o, p_ray.v, vals->y);
	if ((fabs(vals->x) <= 1e-5) || (dis(top_center, top) > cy.cy_r))
		vals->x = 0;
	if ((fabs(vals->y) <= 1e-5) || (dis(bot_center, bot) > cy.cy_r))
		vals->y = 0;
	if (vals->x * vals->y < 0 && scene->obj.flag == 1)
		scene->obj.inside_flag = 1;
	if (vals->x <= 0 && vals->y <= 0)
	{
		if (scene->obj.flag == 1)
			scene->obj.inside_flag = 0;
		return (0);
	}
	return (1);
}

void	get_plane_val(t_cylinder cy, t_ray ray, double *val, t_v norm)
{
	t_plane	pl;
	double	t;

	pl.n_vec = norm;
	pl.op = get_p(cy.cy_origin, norm, cy.cy_height / 2);
	t = get_plane_t(pl, ray);
	*val = t;
}
