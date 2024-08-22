/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:53:20 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/22 19:46:53 by woosupar         ###   ########.fr       */
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
	
}
