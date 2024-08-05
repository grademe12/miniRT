/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:02:23 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/05 21:31:21 by woosupar         ###   ########.fr       */
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

typedef	struct s_color
{
	double	r;
	double	g;
	double	b;
}				t_color;

typedef struct s_ray
{
	t_p	ray_point;
	t_v	ray_vector;
}				t_ray;

typedef struct s_camera
{
	t_p		camera_point;
	t_v		ctv_norm; // 카메라-뷰포트 수직인 단위벡터
	double	viewport_w;
	double	viewport_h;
	t_p		left_top;
	double	fov;
	double	**rotation_matrix;
}				t_camera;

typedef struct s_viewport
{
	int		width;
	int		height;
	double	ratio;
}				t_viewport;

typedef struct s_sphere
{
	t_p		sp_origin;
	double	sp_r;
	t_color	sp_color;
}				t_sphere;

typedef struct s_plane
{
	t_color	plane_color;
}				t_plane;

typedef struct s_cylinder
{
	double	cy_height;
	double	cy_r;
	t_p		cy_origin;
	t_color	cy_color;
}				t_cylinder;

double	v_dot(t_v v1, t_v v2); // 벡터 내적 -> new scalar
t_v		v_cross(t_v v1, t_v v2); // 벡터 외적 -> new vector
t_v		v_plus(t_v v1, t_v v2); // 벡터 합 -> new vector
t_v		v_minus(t_v v1, t_v v2); // 벡터 차 -> new vector
t_v		v_mul(t_v v, double a); // 벡터 스칼라 곱 -> new vector
t_v		v_div(t_v v, double a); // 벡터 스칼라 나누기 -> new vector
double	v_len(t_v v);			// 벡터 길이 -> scalar
t_v		v_norm(t_v v);			// 벡터 정규화. 길이로 나누어서 벡터의 길이가 1이 되게 만드는 놈

//카메라와 viewport 의 길이가 1임을 가정하기 위해, 길이가 1인 단위벡터로 만드는 함수가 필요
t_ray	cam_port_normalize(t_ray ray);

void	render(t_viewport viewport);

#endif
