/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:19:46 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/24 22:21:26 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	shadow_ray(t_scene *scene, t_ray *ret)
{
	ret->ray_vector = get_vec_two_points(scene->obj.val_p, scene->light.origin);
	ret->ray_vector = v_norm(ret->ray_vector);
	if (scene->obj.type == pl)
		shadow_ray_plane(ret, scene);
	if (scene->obj.type == sp)
		shadow_ray_sphere(ret, scene);
	if (scene->obj.type == cy)
		shadow_ray_cylinder(ret, scene);
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
	(get_vec_two_points(scene->obj.val_p, sp_p->sp_origin)).x * 1e-6 * -1;
	ray->ray_point.y = scene->obj.val_p.y + \
	(get_vec_two_points(scene->obj.val_p, sp_p->sp_origin)).y * 1e-6 * -1;
	ray->ray_point.z = scene->obj.val_p.z + \
	(get_vec_two_points(scene->obj.val_p, sp_p->sp_origin)).z * 1e-6 * -1;
}

void	shadow_ray_cylinder(t_ray *ray, t_scene *scene)
{
	t_cylinder	*cy_p;
	
	cy_p = (t_cylinder *)scene->obj.ptr;
	ray->ray_point.x = scene->obj.val_p.x + \
	get_cy_normal(cy_p, scene->obj.val_p, scene).x * 1e-6;
	ray->ray_point.y = scene->obj.val_p.y + \
	get_cy_normal(cy_p, scene->obj.val_p, scene).y * 1e-6;
	ray->ray_point.z = scene->obj.val_p.z + \
	get_cy_normal(cy_p, scene->obj.val_p, scene).z * 1e-6;
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
	if (scene->cam.left_top.x == 0 && scene->cam.left_top.y == 0)
	{
		printf ("%f %f %f\n", scene->obj.val_p.x, scene->obj.val_p.y, scene->obj.val_p.z);
		printf ("ret_val : %d\n", ret_val);
	}
	free(sh_ray);
	return (ret_val);
}