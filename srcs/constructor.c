/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:01:18 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/19 20:47:13 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.c"

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
