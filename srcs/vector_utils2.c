/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:51:12 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/30 15:07:52 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_v	v_div(t_v v, double t)
{
	t_v	ret;

	ret.x = v.x / t;
	ret.y = v.y / t;
	ret.z = v.z / t;
	return (ret);
}

double	v_len(t_v v)
{
	double	ret;

	ret = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (ret);
}

double	dis(t_p p1, t_p p2)
{
	double	ret;

	ret = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2) + \
			pow((p2.z - p1.z), 2));
	return (ret);
}

t_v	v_norm(t_v v)
{
	t_v		ret;
	double	len;

	len = v_len(v);
	if (len == 0)
	{
		ret.x = 0;
		ret.y = 0;
		ret.z = 0;
		return (ret);
	}
	ret.x = v.x / len;
	ret.y = v.y / len;
	ret.z = v.z / len;
	return (ret);
}

void	do_move(t_scene *scene, t_p set)
{
	t_cylinder	*cur_cy;
	t_sphere	*cur_sp;
	t_plane		*cur_pl;

	point_move(&scene->cam.camera_point, set);
	point_move(&scene->li.o, set);
	cur_cy = scene->cy;
	while (cur_cy != 0)
	{
		point_move(&cur_cy->cy_origin, set);
		cur_cy = cur_cy->next;
	}
	cur_sp = scene->sp;
	while (cur_sp != 0)
	{
		point_move(&cur_sp->sp_origin, set);
		cur_sp = cur_sp->next;
	}
	cur_pl = scene->plane;
	while (cur_pl != 0)
	{
		point_move(&cur_pl->op, set);
		cur_pl = cur_pl->next;
	}
}
