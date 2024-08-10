/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:37:33 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/10 15:06:37 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	sphere(t_sphere *sp, t_ray *ray, double *val1, double *val2)
{
	double	a;
	double	b;
	double	c;
	double	disc;

	a = pow(ray->ray_vector.x, 2) + pow(ray->ray_vector.y, 2) + \
		pow(ray->ray_vector.z, 2);
	b = -2 * (sp->sp_origin.x * ray->ray_vector.x + sp->sp_origin.y * \
		ray->ray_vector.y + sp->sp_origin.z * ray->ray_vector.z);
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
		*val1 = (-1 * b) / (2 * a);
		*val2 = *val1;
		return (1);
	}
	if (disc < 0)
		return (0);
	return (0);
}
