/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:11:39 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/31 18:16:56 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	shadow_check(t_scene *scene)
{
	if (scene->obj.ptr == scene->sh_obj.ptr)
		return (0);
	if (dis(scene->obj.val_p, scene->sh_obj.val_p) > \
		dis(scene->obj.val_p, scene->li.o))
		return (0);
	return (1);
}