/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:43:07 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/20 21:53:52 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_p	shoot_plane(t_scene *scene, t_ray p_ray)
{
	t_plane	*pl_ptr;
	t_p		ret;

	pl_ptr = scene->plane;
	while (pl_ptr != 0)
	{
		ret = plane(scene, p_ray);
		pl_ptr++;
	}
	return (ret);
}

t_p	shoot_cylinder(t_scene *scene, t_ray p_ray)
{
	t_cylinder	*cy;
	double		val1;
	double		val2;

	cy = scene->cy;
	while (cy != 0)
	{
		
	}
}