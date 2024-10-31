/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:53:20 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/31 21:15:33 by woosupar         ###   ########.fr       */
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
		pixel->r = min(scene->amb.r * scene->amb.clr.r, 255);
		pixel->g = min(scene->amb.r * scene->amb.clr.g, 255);
		pixel->b = min(scene->amb.r * scene->amb.clr.b, 255);
	}
	if (cy != 0)
	{
		pixel->r = min(scene->amb.r * scene->amb.clr.r, 255);
		pixel->g = min(scene->amb.r * scene->amb.clr.g, 255);
		pixel->b = min(scene->amb.r * scene->amb.clr.b, 255);
	}
	if (pl != 0)
	{
		pixel->r = min(scene->amb.r * scene->amb.clr.r, 255);
		pixel->g = min(scene->amb.r * scene->amb.clr.g, 255);
		pixel->b = min(scene->amb.r * scene->amb.clr.b, 255);
	}
}

void	pixel_light(t_color *p, t_obj tmp, t_scene *scene)
{
	double		coef;
	t_sphere	*sp;
	t_cylinder	*cy;
	t_plane		*pl;

	coef = get_light_coef(*scene, tmp);
	if (scene->cam.left_top.x == 0 && scene->cam.left_top.y == 0)
		printf ("coef : %f\n", coef);
	type_casting(tmp, &sp, &pl, &cy);
	if (sp != 0)
	{
		p->r = min(sp->clr.r * coef + (scene->amb.clr.r * scene->amb.r), 255);
		p->g = min(sp->clr.g * coef + (scene->amb.clr.g * scene->amb.r), 255);
		p->b = min(sp->clr.b * coef + (scene->amb.clr.b * scene->amb.r), 255);
	}
	if (cy != 0)
	{
		p->r = min(cy->clr.r * coef + (scene->amb.clr.r * scene->amb.r), 255);
		p->g = min(cy->clr.g * coef + (scene->amb.clr.g * scene->amb.r), 255);
		p->b = min(cy->clr.b * coef + (scene->amb.clr.b * scene->amb.r), 255);
	}
	if (pl != 0)
	{
		p->r = min(pl->clr.r * coef + (scene->amb.clr.r * scene->amb.r), 255);
		p->g = min(pl->clr.g * coef + (scene->amb.clr.g * scene->amb.r), 255);
		p->b = min(pl->clr.b * coef + (scene->amb.clr.b * scene->amb.r), 255);
	}
}

void	pixel_nothing(t_color *pixel)
{
	pixel->r = 10;
	pixel->g = 10;
	pixel->b = 10;
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}
