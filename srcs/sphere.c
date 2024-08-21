/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:37:33 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/21 20:36:06 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	sphere(t_sphere *sp_p, t_ray p_ray, t_scene *scene)
{
	int		ret;
	double	val1;
	double	val2;
	t_p		rend_p;
	
	ret = sphere_val(sp_p, p_ray, &val1, &val2);
	if (val1 >= val2)
		rend_p = point_multi_vector(p_ray.ray_vector, val2);
	else
		rend_p = point_multi_vector(p_ray.ray_vector, val1);
	if (ret >= 1)
	{
		save_distance(scene, sp, rend_p, sp_p->sp_color);
		return (1);
	}
	return (0);
}

int	sphere_val(t_sphere *sp, t_ray p_ray, double *val1, double *val2)
{
	double	a;
	double	b;
	double	c;
	double	disc;

	a = pow(p_ray.ray_vector.x, 2) + pow(p_ray.ray_vector.y, 2) + \
		pow(p_ray.ray_vector.z, 2);
	b = -2 * (sp->sp_origin.x * p_ray.ray_vector.x + sp->sp_origin.y * \
		p_ray.ray_vector.y + sp->sp_origin.z * p_ray.ray_vector.z);
	c = pow(sp->sp_origin.x, 2) + pow(sp->sp_origin.y, 2) + pow(sp->sp_origin.z, 2) - \
		pow(sp->sp_r, 2);
	disc = pow(b, 2) - 4 * a * c;
	if (disc > 0)
	{
		*val1 = ((-1 * b) + sqrt(disc)) / (2 * a);
		*val2 = ((-1 * b) - sqrt(disc)) / (2 * a);
		return (2);
	}
	if (disc == 0)
	{
		*val1 = ((-1 * b) + sqrt(disc)) / (2 * a);
		*val2 = *val1;
		return (1);
	}
	return (0);
}
