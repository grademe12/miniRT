/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:19:01 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/31 22:00:56 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	get_light_coef(t_scene scene, t_obj tmp)
{
	double	ret;
	double	diff;

	ret = 0;
	diff = diffuse_reflection(&scene, tmp.val_p, tmp);
	ret = ret + diff;
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
		normal = v_norm(get_vec(val_p, sp->sp_origin));
	if (pl != 0)
		normal = pl->n_vec;
	if (cy != 0)
		normal = get_cy_normal(cy, val_p);
	ret = v_dot(normal, v_norm(get_vec(scene->li.o, scene->obj.val_p)));
	if (ret < 0)
		ret *= -1;
	ret *= scene->li.ratio;
	return (ret);
}

int	over_light(t_scene *scene, t_v normal)
{
	t_v	l_to_val;

	l_to_val = v_norm(get_vec(scene->li.o, scene->obj.val_p));
}

void	type_casting(t_obj tmp, t_sphere **sp_p, t_plane **pl_p, \
					t_cylinder **cy_p)
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
