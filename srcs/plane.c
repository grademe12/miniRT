/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:57:15 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/29 00:39:03 by woosupar         ###   ########.fr       */
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
	val = point_multi_vector(p_ray.v, t);
	if (scene->obj.flag == 0)
	{
		if (scene->cam.left_top.x == 0 && scene->cam.left_top.y == 0)
			printf ("%f %f %f\n", val.x, val.y, val.z);
		if (dis(p_ray.o, scene->li.o) < \
		dis(p_ray.o, val))
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
	t = (d + a * p_ray.o.x + b * p_ray.o.y + c * \
		p_ray.o.z) * -1 / (a * p_ray.v.x + b * \
		p_ray.v.y + c * p_ray.v.z);
	if (t < 0)
		return (-1);
	return (t);
}

int	check_par(t_plane pl, t_ray p_ray)
{
	if (fabs(pl.n_vec.x * p_ray.v.x \
	+ pl.n_vec.y * p_ray.v.y \
	+ pl.n_vec.z * p_ray.v.z) < 1e-6)
		return (-1);
	return (0);
}
