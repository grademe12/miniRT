/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:57:15 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/21 02:27:47 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	plane(t_scene *scene, t_ray p_ray)
{
	double	t;
	t_p		val;

	t = get_plane_t(*scene->plane, p_ray);
	if (t < 0)
		return (0);
	val = get_plane_val(p_ray, t);
	save_distance(scene, distance(p_ray.ray_point, val), pl, val);
	return (1);
}

t_p	get_plane_val(t_ray p_ray, double t)
{
	t_p	ret;

	ret.x = p_ray.ray_point.x + t * p_ray.ray_vector.x;
	ret.y = p_ray.ray_point.y + t * p_ray.ray_vector.y;
	ret.z = p_ray.ray_point.z + t * p_ray.ray_vector.z;
	return (ret);
}

double	get_plane_t(t_plane pl, t_ray p_ray)
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	t;

	if (check_par(pl, p_ray) == -1)
		return (-1);
	a = pl.n_vec.x;
	b = pl.n_vec.y;
	c = pl.n_vec.z;
	d = (a * pl.op.x + b * pl.op.y + c * pl.op.z) * -1;
	t = (d + a * p_ray.ray_point.x + b * p_ray.ray_point.y + c * p_ray.ray_point.z) * -1 \
		/ (a * p_ray.ray_vector.x + b * p_ray.ray_vector.y + c * p_ray.ray_vector.z);
	return (t);
}

int	check_par(t_plane pl, t_ray p_ray)
{
	if ((pl.n_vec.x * p_ray.ray_vector.x \
	+  pl.n_vec.y * p_ray.ray_vector.y \
	+ pl.n_vec.z * p_ray.ray_vector.z) == 0)
		return (-1);
	return (0);
}
