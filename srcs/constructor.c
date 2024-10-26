/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:46:20 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/26 17:09:29 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_v	v_build(double x, double y, double z)
{
	t_v	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_p	p_build(double x, double y, double z)
{
	t_p	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_v	get_vec_two_points(t_p p1, t_p p2)
{
	t_v	ret;

	ret.x = p2.x - p1.x;
	ret.y = p2.y - p1.y;
	ret.z = p2.z - p1.z;
	return (ret);
}

t_p	get_p(t_p origin, t_v normal, double t)
{
	t_p	ret;

	ret.x = origin.x + t * normal.x;
	ret.y = origin.y + t * normal.y;
	ret.z = origin.z + t * normal.z;
	return (ret);
}
