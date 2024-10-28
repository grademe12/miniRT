/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:26:01 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/29 04:15:10 by woosupar         ###   ########.fr       */
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

int	plane_check(t_v v, t_p p, t_p val_p)
{
	if (fabs((v.x * (val_p.x - p.x)) + \
		(v.y * (val_p.y - p.y)) + \
		(v.z * (val_p.z - p.z))) < 1e-5)
		return (1);
	return (0);
}
