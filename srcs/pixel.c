/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:53:20 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/24 17:15:26 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	pixel_shadow(t_color *pixel)
{
	pixel->b = 0;
	pixel->r = 0;
	pixel->b = 0;
}

void	pixel_light(t_color *pixel, t_obj tmp, t_scene *scene)
{
	double		coef;
	t_sphere	*sp;
	t_cylinder	*cy;
	t_plane		*pl;

	coef = get_light_coef(scene->amb, *scene, tmp);
	type_casting(tmp, &sp, &pl, &cy);
	if (sp != 0)
	{
		pixel->r = sp->sp_color.r * coef;
		pixel->g = sp->sp_color.g * coef;
		pixel->b = sp->sp_color.b * coef;
	}
	if (cy != 0)
	{
		pixel->r = cy->cy_color.r * coef;
		pixel->g = cy->cy_color.g * coef;
		pixel->b = cy->cy_color.b * coef;
	}
	if (pl != 0)
	{
		pixel->r = pl->plane_color.r * coef;
		pixel->g = pl->plane_color.g * coef;
		pixel->b = pl->plane_color.b * coef;
	}
}
