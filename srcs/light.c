/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:19:01 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/24 17:07:35 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	get_light_coef(t_amb amb, t_scene scene, t_obj tmp)
{
	double	ret;

	ret = 0;
	ret = ret + amb.ratio;
	ret = ret + diffuse_reflection(&scene, tmp.val_p, tmp);
	if (ret > 1)
		ret = 1;
	return (ret);
}

double	diffuse_reflection(t_scene *scene, t_p val_p, t_obj tmp)
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
	t_v			normal;
	double		ret;

	type_casting(tmp, &sp, &pl, &cy);
	if (sp != 0)
		normal = get_vec_two_points(sp->sp_origin, val_p);
	if (pl != 0)
		normal = pl->n_vec;
	if (cy != 0)
		normal = get_cy_normal(cy, val_p);
	normal = v_norm(normal);
	ret = v_dot(normal, v_norm(get_vec_two_points(val_p, scene->light.origin)));
	if (pl != 0 && ret < 0)
		ret = ret * -1;
	if (ret < 0)
		return (0);
	ret *= scene->light.ratio;
	return (ret);
}

void	type_casting(t_obj tmp, t_sphere **sp_p, t_plane **pl_p, t_cylinder **cy_p)
{
	if (tmp.type == cy)
	{
		*cy_p = (t_cylinder *)tmp.ptr;
		*pl_p = 0;
		*sp_p = 0;
	}
	if (tmp.type == pl)
	{
		*pl_p = (t_plane *)tmp.ptr;
		*cy_p = 0;
		*sp_p = 0;
	}
	if (tmp.type == sp)
	{
		*sp_p = (t_sphere *)tmp.ptr;
		*pl_p = 0;
		*cy_p = 0;
	}
}

t_v	get_cy_normal(t_cylinder *cy, t_p val_p)
{
	t_v	top;
	t_v	bot;
	t_p	c_c_top;
	t_p	c_c_bottom;

	c_c_top = get_c_c_top(*cy);
	c_c_bottom = get_c_c_bottom(*cy);
	top = get_vec_two_points(c_c_top, cy->cy_origin);
	bot = get_vec_two_points(c_c_bottom, cy->cy_origin);
	if (plane_check(top, val_p))
		return (top);
	if (plane_check(bot, val_p))
		return (bot);
	else
		return (cy_side_normal(cy, val_p));
}

t_v	cy_side_normal(t_cylinder *cy, t_p val_p)
{
	t_v		ret;
	t_p		npoa;
	double	t;

	t = get_cy_side_t(cy, val_p);
	npoa.x = cy->cy_origin.x + t * cy->cy_nv.x;
	npoa.y = cy->cy_origin.y + t * cy->cy_nv.y;
	npoa.z = cy->cy_origin.z + t * cy->cy_nv.z;
	ret.x = val_p.x - npoa.x;
	ret.y = val_p.y - npoa.y;
	ret.z = val_p.z - npoa.z;
	return (v_norm(ret));
}
