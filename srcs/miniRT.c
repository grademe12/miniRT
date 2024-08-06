/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:48:02 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/06 21:25:49 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int main()
{
    t_camera	*cam;
	t_viewport	*vp;
	t_sphere	*sp;

	cam = (t_camera *)malloc(sizeof(t_camera));
	vp = (t_viewport *)malloc(sizeof(t_viewport));
	sp = (t_sphere *)malloc(sizeof(t_sphere));
	cam->camera_point.x = 0;
	cam->camera_point.y = 0;
	cam->camera_point.z = 0;
	cam->ctv_norm.x = 0;
	cam->ctv_norm.y = 0;
	cam->ctv_norm.z = 1;
	cam->viewport_h = 1080;
	cam->viewport_w = 1920;
	vp->height = 1080;
	vp->width = 1920;
	sp->sp_origin.x = 0;
	sp->sp_origin.y = 0;
	sp->sp_origin.z = 10;
	sp->sp_r = 300;

	get_vp_left_top(cam, vp);
	
    return (0);
}
