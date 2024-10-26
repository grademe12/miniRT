/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:51:00 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/26 16:51:01 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	v_dot(t_v v1, t_v v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_v	v_cross(t_v v1, t_v v2)
{
	t_v	ret;

	ret.x = v1.y * v2.z - v1.z * v2.y;
	ret.y = v1.z * v2.x - v1.x * v2.z;
	ret.z = v1.x * v2.y - v1.y * v2.x;
	return (ret);
}

t_v	v_plus(t_v v1, t_v v2)
{
	t_v	ret;

	ret.x = v1.x + v2.x;
	ret.y = v1.y + v2.y;
	ret.z = v1.z + v2.z;
	return (ret);
}

t_v	v_minus(t_v v1, t_v v2)
{
	t_v	ret;

	ret.x = v1.x - v2.x;
	ret.y = v1.y - v2.y;
	ret.z = v1.z - v2.z;
	return (ret);
}

t_v	v_mul(t_v v, double a)
{
	t_v	ret;

	ret.x = v.x * a;
	ret.y = v.y * a;
	ret.z = v.z * a;
	return (ret);
}
