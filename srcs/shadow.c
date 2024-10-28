/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:19:46 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/29 05:02:54 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	shadow_ray(t_scene *scene, t_ray *ret)
{
	ret->v = get_vec_two_points(scene->obj.val_p, scene->li.o);
	ret->v = v_norm(ret->v);
	if (scene->obj.type == pl)
		shadow_ray_plane(ret, scene);
	if (scene->obj.type == sp)
		shadow_ray_sphere(ret, scene);
	if (scene->obj.type == cy)
		shadow_ray_cylinder(ret, scene);
}

void	shadow_ray_plane(t_ray *ray, t_scene *scene)
{
	ray->o.x = scene->obj.val_p.x + ray->v.x * 1e-6;
	ray->o.y = scene->obj.val_p.y + ray->v.y * 1e-6;
	ray->o.z = scene->obj.val_p.z + ray->v.z * 1e-6;
}

void	shadow_ray_sphere(t_ray *ray, t_scene *scene)
{
	t_sphere	*sp_p;
	t_v			normal;

	sp_p = (t_sphere *)scene->obj.ptr;
	normal = v_norm(get_vec_two_points(scene->obj.val_p, sp_p->sp_origin));
	ray->o = get_p(scene->obj.val_p, normal, -1e-6);
}

void	shadow_ray_cylinder(t_ray *ray, t_scene *scene)
{
	t_cylinder	*cy_p;

	cy_p = (t_cylinder *)scene->obj.ptr;
	ray->o.x = scene->obj.val_p.x + \
	get_cy_normal(cy_p, scene->obj.val_p).x * 1e-6;
	ray->o.y = scene->obj.val_p.y + \
	get_cy_normal(cy_p, scene->obj.val_p).y * 1e-6;
	ray->o.z = scene->obj.val_p.z + \
	get_cy_normal(cy_p, scene->obj.val_p).z * 1e-6;
}

int	object_shadow(t_scene *scene)
{
	int		ret_val;
	t_ray	*sh_ray;

	sh_ray = (t_ray *)malloc(sizeof(t_ray));
	if (sh_ray == 0)
		exit (1);
	shadow_ray(scene, sh_ray);
	ret_val = 0;
	ret_val |= shoot_plane(scene, *sh_ray);
	ret_val |= shoot_sphere(scene, *sh_ray);
	ret_val |= shoot_cylinder(scene, *sh_ray);
	free(sh_ray);
	return (ret_val);
}
