/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:37:33 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/25 23:19:58 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	sphere(t_sphere *sp_p, t_ray p_ray, t_scene *scene)
{
	int		ret;
	double	val1;
	double	val2;
	void	*ptr;
	t_p		rend_p;
	
	ret = sphere_val(sp_p, p_ray, &val1, &val2);
	if (val1 * val2 < 0)
		scene->obj.inside_flag = 1;
	if (ret == 0)
		return (0);
	if (val1 * val2 > 0 && val1 >= val2)
		rend_p = point_multi_vector(p_ray.ray_vector, val2);
	else if (val1 * val2 > 0 && val1 < val2)
		rend_p = point_multi_vector(p_ray.ray_vector, val1);
	else if (val1 * val2 < 0 && val1 >= val2)
		rend_p = point_multi_vector(p_ray.ray_vector, val1);
	else if (val1 * val2 < 0 && val1 < val2)
		rend_p = point_multi_vector(p_ray.ray_vector, val2);
	ptr = sp_p;
	if (ret > 0)
		save_distance(scene, sp, rend_p, ptr);
	return (1);
}

int sphere_val(t_sphere *sp, t_ray p_ray, double *val1, double *val2)
{
	double a;
	double b;
	double c;
	double disc;
	t_v oc;

	oc = get_vec_two_points(sp->sp_origin, p_ray.ray_point);
	a = pow(p_ray.ray_vector.x, 2) + pow(p_ray.ray_vector.y, 2) + pow(p_ray.ray_vector.z, 2);
	b = 2 * (oc.x * p_ray.ray_vector.x + oc.y * p_ray.ray_vector.y + oc.z * p_ray.ray_vector.z);
	c = pow(oc.x, 2) + pow(oc.y, 2) + pow(oc.z, 2) - pow(sp->sp_r, 2);
	disc = pow(b, 2) - 4 * a * c;
	if (disc < 0)
		return (0);
	*val1 = ((-1 * b) + sqrt(disc)) / (2 * a);
	*val2 = ((-1 * b) - sqrt(disc)) / (2 * a);
	if (*val1 < 0 && *val2 < 0)
		return (0);
	return (1);
}

int	sphere_shadow(t_sphere *sp, t_ray sh_ray, t_scene *scene)
{
	double	val1;
	double	val2;
	double	min;
	t_p		max_p;
	t_p		min_p;

	if (sphere_val(sp, sh_ray, &val1, &val2) == 0)
		return (0);
	if (val1 < 0 && val2 < 0)
		return (0);
	min = double_min(val1, val2);
	min_p = get_p(sh_ray.ray_point, sh_ray.ray_vector, min);
	max_p = get_p(sh_ray.ray_point, sh_ray.ray_vector, double_max(val1, val2));
	if (val1 > 0 && val2 > 0 && distance(min_p, sh_ray.ray_point) <= \
	1e-5 && (distance(sh_ray.ray_point, max_p) > distance(sh_ray.ray_point, \
	scene->light.origin)))
		return (0);
	if (min < 0 && distance(max_p, sh_ray.ray_point) > \
	distance(sh_ray.ray_point, scene->light.origin))
		return (0);
	if (double_max(val1, val2) < 0 && distance(min_p, sh_ray.ray_point) > \
	distance(sh_ray.ray_point, scene->light.origin))
		return (0);
	return (1);	
}

double	double_min(double val1, double val2)
{
	if (val1 < val2)
		return (val1);
	return (val2);
}

double	double_max(double val1, double val2)
{
	if (val1 > val2)
		return (val1);
	return (val2);
}