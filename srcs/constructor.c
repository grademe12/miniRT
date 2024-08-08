/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:01:18 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/08 19:55:57 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_v	v_build(double x, double y, double z)
{
    t_v	ret;

    ret.x = x;
    ret.y = y;
    ret.z = z;
    return (ret);
}

t_p	p_build(double x, double y, double z)
{
    t_p	ret;

    ret.x = x;
    ret.y = y;
    ret.z = z;
    return (ret);
}

t_ray	cam_port_normalize(t_ray ray)
{
	t_ray	ret;

	ret.ray_point = ray.ray_point;
	ret.ray_vector = v_norm(ray.ray_vector);
	return (ret);
}

void	get_vp_left_top(t_camera *camera, t_viewport *viewport)
{
	t_p	vp_center;

	vp_center.x = camera->camera_point.x + camera->ctv_norm.x;
	vp_center.y = camera->camera_point.y + camera->ctv_norm.y;
	vp_center.z = camera->camera_point.z + 1000 * camera->ctv_norm.z;
	camera->left_top.x = vp_center.x - viewport->width / 2;
	camera->left_top.y = vp_center.y + viewport->height / 2;
	camera->left_top.z = vp_center.z;
}

t_v	get_vec_two_points(t_p p1, t_p p2)
{
	t_v	ret;

	ret.x = p2.x - p1.x;
	ret.y = p2.y - p1.y;
	ret.z = p2.z - p1.z;
	return (ret);
}