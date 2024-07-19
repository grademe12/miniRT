/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:02:23 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/19 21:05:15 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <unistd.h>

typedef struct s_vector
{
    double	x;
    double	y;
    double	z;
}				t_v;

typedef struct s_point
{
    double	x;
    double	y;
    double	z;
}				t_p;

typedef struct s_axis
{
	t_v	x;
	t_v	y;
	t_v	z;
}				t_axis;

typedef struct s_canvas
{
	int	width;
	int	height;
}				t_canvas;

typedef	struct s_color
{
	double	r;
	double	g;
	double	b;
}				t_color;

#endif
