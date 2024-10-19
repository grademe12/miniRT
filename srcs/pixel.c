/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:53:20 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/19 20:43:46 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	pixel_shadow(t_color *pixel, t_obj tmp, t_scene *scene)
{
	t_sphere	*sp;
	t_cylinder	*cy;
	t_plane		*pl;

	type_casting(tmp, &sp, &pl, &cy);
	if (sp != 0)
	{
		pixel->r = min(scene->amb.ratio * scene->amb.a_color.r, 255);
		pixel->g = min(scene->amb.ratio * scene->amb.a_color.g, 255);
		pixel->b = min(scene->amb.ratio * scene->amb.a_color.b, 255);
	}
	if (cy != 0)
	{
		pixel->r = min(scene->amb.ratio * scene->amb.a_color.r, 255);
		pixel->g = min(scene->amb.ratio * scene->amb.a_color.g, 255);
		pixel->b = min(scene->amb.ratio * scene->amb.a_color.b, 255);
	}
	if (pl != 0)
	{
		pixel->r = min(scene->amb.ratio * scene->amb.a_color.r, 255);
		pixel->g = min(scene->amb.ratio * scene->amb.a_color.g, 255);
		pixel->b = min(scene->amb.ratio * scene->amb.a_color.b, 255);
	}
}

void	 pixel_light(t_color *pixel, t_obj tmp, t_scene *scene)
{
	double		coef;
	t_sphere	*sp;
	t_cylinder	*cy;
	t_plane		*pl;

	coef = get_light_coef(*scene, tmp);
	type_casting(tmp, &sp, &pl, &cy);
	if (sp != 0)
	{
		pixel->r = min(sp->sp_color.r * coef + (scene->amb.a_color.r * scene->amb.ratio), 255);
		pixel->g = min(sp->sp_color.g * coef + (scene->amb.a_color.g * scene->amb.ratio), 255);
		pixel->b = min(sp->sp_color.b * coef + (scene->amb.a_color.b * scene->amb.ratio), 255);
	}
	if (cy != 0)
	{
		pixel->r = min(cy->cy_color.r * coef + (scene->amb.a_color.r * scene->amb.ratio), 255);
		pixel->g = min(cy->cy_color.g * coef + (scene->amb.a_color.g * scene->amb.ratio), 255);
		pixel->b = min(cy->cy_color.b * coef + (scene->amb.a_color.b * scene->amb.ratio), 255);
	}
	if (pl != 0)
	{
		pixel->r = min(pl->plane_color.r * coef + (scene->amb.a_color.r * scene->amb.ratio), 255);
		pixel->g = min(pl->plane_color.g * coef + (scene->amb.a_color.g * scene->amb.ratio), 255);
		pixel->b = min(pl->plane_color.b * coef + (scene->amb.a_color.b * scene->amb.ratio), 255);
	}
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}