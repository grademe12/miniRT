/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:37:33 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/31 21:56:47 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	sphere(t_sphere *sp_p, t_ray p_ray, t_scene *scene)
{
	double	val1;
	double	val2;
	void	*ptr;
	t_p		rend_p;

	if (sphere_val(sp_p, p_ray, &val1, &val2) == 0)
		return (0);
	rend_p = p_build(0, 0, 0);
	if (val1 < 0 && val2 < 0)
		return (0);
	if (val1 * val2 < 0)
		scene->obj.inside_flag = 1;
	if (val1 * val2 > 0 && val1 >= val2)
		rend_p = get_p(p_ray.o, p_ray.v, val2);
	else if (val1 * val2 > 0 && val1 < val2)
		rend_p = get_p(p_ray.o, p_ray.v, val1);
	else if (val1 * val2 < 0 && val1 >= val2)
		rend_p = get_p(p_ray.o, p_ray.v, val1);
	else if (val1 * val2 < 0 && val1 < val2)
		rend_p = get_p(p_ray.o, p_ray.v, val2);
	ptr = sp_p;
	save_distance(scene, sp, rend_p, ptr);
	return (1);
}

int	sphere_val(t_sphere *sp, t_ray p_ray, double *val1, double *val2)
{
	double	a;
	double	b;
	double	c;
	double	disc;
	t_v		oc;

	oc = get_vec(sp->sp_origin, p_ray.o);
	a = pow(p_ray.v.x, 2) + pow(p_ray.v.y, 2) + \
	pow(p_ray.v.z, 2);
	b = 2 * (oc.x * p_ray.v.x + oc.y * p_ray.v.y + \
	oc.z * p_ray.v.z);
	c = pow(oc.x, 2) + pow(oc.y, 2) + pow(oc.z, 2) - pow(sp->sp_r, 2);
	disc = pow(b, 2) - 4 * a * c;
	if (disc <= 0)
		return (0);
	*val1 = ((-1 * b) + sqrt(disc)) / (2 * a);
	*val2 = ((-1 * b) - sqrt(disc)) / (2 * a);
	if (fabs(*val1) <= 1e-5)
		*val1 = 0;
	if (fabs(*val2) <= 1e-5)
		*val2 = 0;
	if (*val1 == 0 && *val2 == 0)
		return (0);
	return (1);
}

int	sphere_shadow(t_sphere *sp, t_ray sh_ray, t_scene *scene)
{
	t_sol	sol;

	if (sphere_val(sp, sh_ray, &sol.vals.x, &sol.vals.y) == 0)
		return (0);
	if (get_sphere_sol(sp, sh_ray, scene, &sol) == 0)
		return (0);
	return (1);
}

double	fmin(double val1, double val2)
{
	if (val1 < val2)
		return (val1);
	return (val2);
}

double	fmax(double val1, double val2)
{
	if (val1 > val2)
		return (val1);
	return (val2);
}
