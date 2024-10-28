/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:33:49 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/29 04:53:17 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	define_side_sol(t_scene *scene, t_ray p_ray, t_p vals, t_p *sol)
{
	if (vals.x * vals.y < 0 && scene->obj.flag == 1)
		scene->obj.inside_flag = 1;
	if (scene->obj.flag == 0 && scene->obj.inside_flag == 1)
	{
		if (vals.x > 0 && vals.y > 0 && fabs(fmin(vals.x, vals.y)) <= 1e-6)
			return (0);
		if (vals.x < 0 && vals.y < 0 && fabs(fmax(vals.x, vals.y)) <= 1e-4)
		{
			*sol = get_p(p_ray.o, p_ray.v, fmax(vals.x, vals.y));
			return (1);
		}
	}
	if (vals.x * vals.y > 0 && vals.x >= vals.y && fabs(vals.y) > 1e-6)
		*sol = get_p(p_ray.o, p_ray.v, vals.y);
	if (vals.x * vals.y > 0 && vals.x >= vals.y && fabs(vals.y) <= 1e-6)
		*sol = get_p(p_ray.o, p_ray.v, vals.x);
	if (vals.x * vals.y > 0 && vals.x < vals.y && fabs(vals.x) > 1e-6)
		*sol = get_p(p_ray.o, p_ray.v, vals.x);
	if (vals.x * vals.y > 0 && vals.x < vals.y && fabs(vals.x) <= 1e-6)
		*sol = get_p(p_ray.o, p_ray.v, vals.y);
	if (vals.x * vals.y < 0 && vals.x >= vals.y)
		*sol = get_p(p_ray.o, p_ray.v, vals.x);
	if (vals.x * vals.y < 0 && vals.x < vals.y)
		*sol = get_p(p_ray.o, p_ray.v, vals.y);
	return (1);
}
