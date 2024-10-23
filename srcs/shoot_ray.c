/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:43:07 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/23 23:36:54 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	shoot_plane(t_scene *scene, t_ray p_ray)
{
	t_plane	*pl;
	int		ret;

	ret = 0;
	pl = scene->plane;
	while (pl != NULL)
	{
		ret |= plane(pl, scene, p_ray);
		pl = pl->next;
	}
	if (ret != 0)
		return (1);
	return (ret);
}

int	shoot_cylinder(t_scene *scene, t_ray p_ray)
{
	t_cylinder	*cy;
	int			ret;

	ret = 0;
	cy = scene->cy;
	while (cy != 0)
	{
		if (scene->obj.flag == 1)
			ret |= cylinder(cy, p_ray, scene);
		else
			ret |= cylinder_shadow(cy, p_ray, scene);
		cy = cy->next;
	}
	if (ret != 0)
		return (1);
	return (ret);
}

int	shoot_sphere(t_scene *scene, t_ray p_ray)
{
	t_sphere	*sp;
	int			ret;

	ret = 0;
	sp = scene->sp;
	while (sp != 0)
	{
		if (scene->obj.flag == 1)
			ret |= sphere(sp, p_ray, scene);
		else
			ret |= sphere_shadow(sp, p_ray, scene);
		sp = sp->next;
	}
	if (ret != 0)
		return (1);
	return (ret);
}
