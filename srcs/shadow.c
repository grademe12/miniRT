/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:19:46 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/11 21:08:31 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_ray	shadow_ray(t_scene scene, t_p val)
{
	t_ray	ret;

	ret.ray_vector = get_vec_two_points(val, scene.light.origin);
	ret.ray_vector = v_norm(ret.ray_vector);
	ret.ray_point = val;
	return (ret);
}

int	object_shadow(t_scene scene, t_p val)
{
	int		ret_val;
	t_ray	sh_ray;

	sh_ray = shadow_ray(scene, val);
	ret_val = sphere(scene.sp, &sh_ray, 0, 0);
	return (ret_val);
}