/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:57:15 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/23 23:33:47 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	plane(t_plane *pl_p, t_scene *scene, t_ray p_ray)
{
	double	t;
	t_p		val;
	void	*ptr;

	t = get_plane_t(*pl_p, p_ray);
	if (t <= 0)
		return (0);
	val = point_multi_vector(p_ray.ray_vector, t);
	if (scene->obj.flag == 0)
	{
		if (scene->cam.left_top.x == 0 && scene->cam.left_top.y == 0)
			printf ("%f %f %f\n", val.x, val.y, val.z);
		if (distance(p_ray.ray_point, scene->light.origin) < distance(p_ray.ray_point, val))
			return (0);
	}	
	ptr = pl_p;
	save_distance(scene, pl, val, ptr);
	return (1);
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
	if (fabs(pl.n_vec.x * p_ray.ray_vector.x \
	+  pl.n_vec.y * p_ray.ray_vector.y \
	+ pl.n_vec.z * p_ray.ray_vector.z) < 1e-6)
		return (-1);
	return (0);
}
