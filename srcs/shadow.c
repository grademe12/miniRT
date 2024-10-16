/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:19:46 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/22 18:50:17 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_ray	shadow_ray(t_scene *scene)
{
	t_ray	ret;

	ret.ray_vector = get_vec_two_points(scene->obj.val_p, scene->light.origin);
	ret.ray_vector = v_norm(ret.ray_vector);
	ret.ray_point = scene->obj.val_p;
	return (ret);
}

int	object_shadow(t_scene *scene)
{
	int		ret_val;
	t_ray	sh_ray;

	sh_ray = shadow_ray(scene);
	ret_val = shoot_plane(scene, sh_ray);
	ret_val = shoot_sphere(scene, sh_ray);
	ret_val = shoot_cylinder(scene, sh_ray);
	return (ret_val);
}