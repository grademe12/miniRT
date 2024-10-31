/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:57:40 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/31 14:53:38 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	point_move(t_p *origin, t_p set)
{
	origin->x = origin->x + set.x;
	origin->y = origin->y + set.y;
	origin->z = origin->z + set.z;
}

void	rotate_vector(t_v *vec, t_v axis, double theta)
{
	double	cos_th;
	double	sin_th;
	t_v		cross;
	double	dot;

	cos_th = cos(theta);
	sin_th = sin(theta);
	dot = v_dot(*vec, axis);
	cross = v_cross(*vec, axis);
	vec->x = vec->x * cos_th + cross.x * sin_th + axis.x * dot * (1 - cos_th);
	vec->y = vec->y * cos_th + cross.y * sin_th + axis.y * dot * (1 - cos_th);
	vec->z = vec->z * cos_th + cross.z * sin_th + axis.z * dot * (1 - cos_th);
}

void	move_object(t_scene *scene)
{
	t_p			set;

	set.x = 0 - scene->cam.camera_point.x;
	set.y = 0 - scene->cam.camera_point.y;
	set.z = 0 - scene->cam.camera_point.z;
	do_move(scene, set);
}

void	rotate_object(t_scene *scene)
{
	t_v		axis;
	double	theta;
	double	dot;

	axis = v_norm(v_cross(scene->cam.ctv_norm, v_build(0, 0, 1)));
	dot = v_dot(scene->cam.ctv_norm, v_build(0, 0, 1));
	if (dot < -1)
		dot = -1;
	if (dot > 1)
		dot = 1;
	theta = acos(dot);
	if (dot <= 0)
		theta = -1 * theta;
	if (!(axis.x == 0 && axis.y == 0 && axis.z == 0))
		rotating(scene, axis, theta);
}

void	rotating(t_scene *scene, t_v axis, double theta)
{
	t_cylinder	*cur_cy;
	t_plane		*cur_pl;

	rotate_vector(&scene->cam.ctv_norm, axis, theta);
	cur_cy = scene->cy;
	while (cur_cy != 0)
	{
		rotate_vector(&cur_cy->cy_nv, axis, theta);
		cur_cy = cur_cy->next;
	}
	cur_pl = scene->plane;
	while (cur_pl != 0)
	{
		rotate_vector(&cur_pl->n_vec, axis, theta);
		cur_pl = cur_pl->next;
	}
}
