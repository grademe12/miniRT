/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:57:15 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/11 21:52:11 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	plane(t_scene scene, t_ray p_ray)
{
	double	t;
	t_p		val_p;

	t = get_plane_t(scene, p_ray);
	val_p = get_plane_val(p_ray, t);
	if (distance(p_ray.ray_point, val_p) > 1000)
		t = -1;
	if (t > 0)
		return (1);
	return (0);
}

t_p	get_plane_val(t_ray p_ray, double t)
{
	t_p	ret;

	ret.x = p_ray.ray_point.x + t * p_ray.ray_vector.x;
	ret.y = p_ray.ray_point.y + t * p_ray.ray_vector.y;
	ret.z = p_ray.ray_point.z + t * p_ray.ray_vector.z;
	return (ret);
}

double	get_plane_t(t_scene scene, t_ray p_ray)
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	t;

	if (check_par(scene, p_ray) == -1)
		return (-1);
	a = scene.plane->n_vec.x;
	b = scene.plane->n_vec.y;
	c = scene.plane->n_vec.z;
	d = (a * scene.plane->op.x + b * scene.plane->op.y + c * scene.plane->op.z) * -1;
	t = (d + a * p_ray.ray_point.x + b * p_ray.ray_point.y + c * p_ray.ray_point.z) * -1 \
		/ (a * p_ray.ray_vector.x + b * p_ray.ray_vector.y + c * p_ray.ray_vector.z);
	return (t);
}

int	check_par(t_scene scene, t_ray p_ray)
{
	if ((scene.plane->n_vec.x * p_ray.ray_vector.x \
	+  scene.plane->n_vec.y * p_ray.ray_vector.y \
	+ scene.plane->n_vec.z * p_ray.ray_vector.z) == 0)
		return (-1);
	return (0);
}