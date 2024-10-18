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
	if (scene->obj.type == pl)
		shadow_ray_plane(&ret, scene);
	if (scene->obj.type == sp)
		shadow_ray_sphere(&ret, scene);
	// if (scene->obj.type == cy)
	// 	shadow_ray_cylinder(&ret);
	ret.ray_point.x = scene->obj.val_p.x + ret.ray_vector.x * 1e-6;
	ret.ray_point.y = scene->obj.val_p.y + ret.ray_vector.y * 1e-6;
	ret.ray_point.z = scene->obj.val_p.z + ret.ray_vector.z * 1e-6;
	return (ret);
}

void	shadow_ray_plane(t_ray *ray, t_scene *scene)
{
	ray->ray_point.x = scene->obj.val_p.x + ray->ray_vector.x * 1e-6;
	ray->ray_point.y = scene->obj.val_p.y + ray->ray_vector.y * 1e-6;
	ray->ray_point.z = scene->obj.val_p.z + ray->ray_vector.z * 1e-6;
}

void	shadow_ray_sphere(t_ray *ray, t_scene *scene)
{
	t_sphere	*sp_p;
	
	sp_p = (t_sphere *)scene->obj.ptr;
	ray->ray_point.x = scene->obj.val_p.x + \
	(get_vec_two_points(sp_p->sp_origin, scene->obj.val_p)).x * 1e-6;
	ray->ray_point.y = scene->obj.val_p.y + \
	(get_vec_two_points(sp_p->sp_origin, scene->obj.val_p)).y * 1e-6;
	ray->ray_point.z = scene->obj.val_p.z + \
	(get_vec_two_points(sp_p->sp_origin, scene->obj.val_p)).z * 1e-6;
}

void	shadow_ray_cylinder(t_ray *ray, t_scene *scene)
{
	(void)ray;
	(void)scene;
}

int	object_shadow(t_scene *scene)
{
	int		ret_val;
	t_ray	sh_ray;

	sh_ray = shadow_ray(scene);
	ret_val = 0;
	ret_val |= shoot_plane(scene, sh_ray);
	ret_val |= shoot_sphere(scene, sh_ray);
	ret_val |= shoot_cylinder(scene, sh_ray);
	return (ret_val);
}