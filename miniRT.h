/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:02:23 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/21 02:34:13 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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
	t_p		op;
	t_v		n_vec;
	t_color	plane_color;
}				t_plane;

typedef struct s_cylinder
{
	double	cy_height;
	double	cy_r;
	t_p		cy_origin;
	t_color	cy_color;
	t_v		cy_nv;
}				t_cylinder;

typedef struct s_ambient
{
	double	ratio;
	t_color	a_color;
}				t_amb;

typedef struct s_light
{
	t_p		origin;
	double	ratio;
}				t_light;


typedef struct s_mlximg
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_len;
	int		endian;
}				t_mlximg;

typedef struct s_mlxdata
{
	void		*mlx;
	void		*window;
	t_mlximg	*mlximg;
}				t_mlxdata;

typedef enum e_type
{
	pl,
	cy,
	sp
}			t_type;

typedef struct s_obj
{
	double	g_distance;
	t_type	type;
	t_p		val_p;
}				t_obj;

typedef struct s_scene
{
	t_sphere	*sp;
	t_plane		*plane;
	t_cylinder	*cy;
	t_light		light;
	t_amb		amb;
	t_camera	*cam;
	t_viewport	vp;
	t_obj		obj;
}				t_scene;

double	v_dot(t_v v1, t_v v2); // 벡터 내적 -> new scalar
t_v		v_cross(t_v v1, t_v v2); // 벡터 외적 -> new vector
t_v		v_plus(t_v v1, t_v v2); // 벡터 합 -> new vector
t_v		v_minus(t_v v1, t_v v2); // 벡터 차 -> new vector
t_v		v_mul(t_v v, double a); // 벡터 스칼라 곱 -> new vector
t_v		v_div(t_v v, double a); // 벡터 스칼라 나누기 -> new vector
double	v_len(t_v v);			// 벡터 길이 -> scalar
t_v		v_norm(t_v v);			// 벡터 정규화. 길이로 나누어서 벡터의 길이가 1이 되게 만드는 놈
double	distance(t_p p1, t_p p2);
t_p		point_multi_vector(t_v v, double t);

t_v		v_build(double x, double y, double z);
t_p		p_build(double x, double y, double z);
//카메라와 viewport 의 길이가 1임을 가정하기 위해, 길이가 1인 단위벡터로 만드는 함수가 필요
t_ray	cam_port_normalize(t_ray ray);
void	get_vp_left_top(t_camera *camera, t_viewport *vp);
t_v		get_vec_two_points(t_p p1, t_p p2);

void	render(t_viewport viewport);

//구 근의 갯수 return
int		sphere(t_sphere *sp, t_ray *ray, double *val1, double *val2);


double	get_light_coef(t_amb amb, t_scene scene, t_p rend_p);
double	diffuse_reflection(t_scene scene, t_p val_p);
t_ray	shadow_ray(t_scene scene, t_p val);
int		object_shadow(t_scene scene, t_p val);

int		plane(t_scene *scene, t_ray p_ray);
int		check_par(t_plane pl, t_ray p_ray);
double	get_plane_t(t_plane pl, t_ray p_ray);
t_p		get_plane_val(t_ray p_ray, double t);

int		cylinder(t_scene *scene, t_ray p_ray, double *val1, double *val2);
int		cylinder_hit(t_scene scene, t_ray p_ray, double *val1, double *val2);
double	get_cy_a(t_cylinder cy, t_ray p_ray);
double	get_cy_b(t_cylinder cy, t_ray p_ray);
double	get_cy_c(t_cylinder cy, t_ray p_ray);

int		cy_cap(t_cylinder cy, t_ray p_ray);
int		cy_cap_hit(t_cylinder cy, t_ray p_ray, t_p c_c);
t_p		get_c_c_top(t_cylinder cy);
t_p 	get_c_c_bottom(t_cylinder cy);

void	draw_rt(t_mlxdata *mlxdata, t_scene scene);
void	save_distance(t_scene *scene, double tmp_dis, int type, t_p val);

int		shoot_plane(t_scene *scene, t_ray p_ray);
int		shoot_cylinder(t_scene *scene, t_ray p_ray);
int		shoot_sphere(t_scene *scene, t_ray p_ray);

#endif