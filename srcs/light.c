/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:19:01 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/10 18:52:20 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	get_light_coef(t_amb amb, t_scene scene, t_p rend_p)
{
	double	ret;

	ret = 0;
	ret = ret + amb.ratio;
	ret = ret + diffuse_reflection(scene, rend_p);
	return (ret);
}

double	diffuse_reflection(t_scene scene, t_p val_p)
{
	t_sphere	*sp;
	t_v			normal;
	t_v			to_light;
	double		ret;

	sp = scene.sp;
	normal = get_vec_two_points(sp->sp_origin, val_p);
	to_light = get_vec_two_points(val_p, scene.light.origin);
	normal = v_norm(normal);
	to_light = v_norm(to_light);
	ret = v_dot(normal, to_light);
	if (ret < 0)
		ret = 0;
	ret *= scene.light.ratio;
	return (ret);
}
