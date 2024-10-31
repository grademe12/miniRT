/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:54:56 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/31 17:18:30 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	get_sphere_sol(t_sphere *sp, t_ray sh_ray, t_scene *scene, t_sol *sol)
{
	(void )sp;
	sol->min = fmin(sol->vals.x, sol->vals.y);
	sol->max = fmax(sol->vals.x, sol->vals.y);
	sol->min_p = get_p(sh_ray.o, sh_ray.v, sol->min);
	sol->max_p = get_p(sh_ray.o, sh_ray.v, sol->max);
	if (sol->min == 0 && dis(sol->max_p, sh_ray.o) > dis(scene->li.o, sh_ray.o))
		return (0);
	if (sol->max == 0 && sol->min < 0)
		return (0);
	if (sol->max == 0 && dis(sol->min_p, sh_ray.o) > dis(scene->li.o, sh_ray.o))
		return (0);
	if (sol->vals.x < 0 && sol->vals.y < 0)
		return (0);
	if (sol->vals.x * sol->vals.y < 0 && dis(sol->max_p, sh_ray.o) > \
		dis(scene->li.o, sh_ray.o))
		return (0);
	return (1);
}
