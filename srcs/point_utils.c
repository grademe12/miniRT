/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:26:01 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/23 20:29:36 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_p	point_minus(t_p p1, t_p p2)
{
	t_p	ret;

	ret.x = p2.x - p1.x;
	ret.y = p2.y - p1.y;
	ret.z = p2.z - p1.z;
	return (ret);
}

float	plane_check(t_v v, t_p p)
{
	if ((v.x * p.x) + (v.y * p.y) + (v.z * p.z) == 0)
		return (1);
	return (0);
}
