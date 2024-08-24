/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:32:41 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/24 16:45:54 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	get_cy_side_t(t_cylinder *cy, t_p val_p)
{
	double	ret;

	ret = (((val_p.x - cy->cy_origin.x) * cy->cy_nv.x) + \
			((val_p.y - cy->cy_origin.y) * cy->cy_nv.y) + \
			((val_p.z - cy->cy_origin.z) * cy->cy_nv.z));
	return (ret);
}