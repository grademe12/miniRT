/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:02:23 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/13 21:35:10 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "openGL/mlx.h"
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

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
	int	r;
	int	g;
	int	b;
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
	int		fov;
	double	**rotation_matrix;
	int		flag;
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
	struct s_sphere	*next;

}				t_sphere;

typedef struct s_plane
{
	t_p				op;
	t_v				n_vec;
	t_color			plane_color;
	struct s_plane	*next;
}				t_plane;

typedef struct s_cylinder
{
	double			cy_height;
	double			cy_r;
	t_p				cy_origin;
	t_color			cy_color;
	t_v				cy_nv;
	struct s_cylinder	*next;
}				t_cylinder;

typedef struct s_ambient
{
	double	ratio;
	t_color	a_color;
	int		flag;
}				t_amb;

typedef struct s_light
{
	t_p		origin;
	double	ratio;
	int		flag;
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
	void	*ptr;
	int		flag;
}				t_obj;

typedef struct s_scene
{
	t_sphere	*sp;
	t_plane		*plane;
	t_cylinder	*cy;
	t_light		light;
	t_amb		amb;
	t_camera	cam;
	t_viewport	vp;
	t_obj		obj;
}				t_scene;

typedef struct s_info
{
	t_scene		*scene;
	t_mlxdata	*mlxdata;
}				t_info;

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
t_p		point_minus(t_p p1, t_p p2);
float	plane_check(t_v v, t_p p);

t_v		v_build(double x, double y, double z);
t_p		p_build(double x, double y, double z);
//카메라와 viewport 의 길이가 1임을 가정하기 위해, 길이가 1인 단위벡터로 만드는 함수가 필요
t_ray	cam_port_normalize(t_ray ray);
void	get_vp_left_top(t_camera *camera, t_viewport *vp);
t_v		get_vec_two_points(t_p p1, t_p p2);

void	render(t_viewport viewport);
void	do_pixel(t_mlxdata *, t_scene *);
void	shoot_ray(t_scene *, t_color *);
void	pixel_shadow(t_color *, t_obj, t_scene *);
void	pixel_light(t_color *, t_obj, t_scene *);

//구 근의 갯수 return
int		sphere(t_sphere *sp, t_ray ray, t_scene *scene);
int		sphere_val(t_sphere *, t_ray, double *, double *);


double	get_light_coef(t_amb amb, t_scene scene, t_obj tmp);
double	diffuse_reflection(t_scene *scene, t_p val_p, t_obj tmp);
t_ray	shadow_ray(t_scene *scene);
int		object_shadow(t_scene *scene);

int		plane(t_plane *pl, t_scene *scene, t_ray p_ray);
float	plane_check(t_v v, t_p p);
int		check_par(t_plane pl, t_ray p_ray);
double	get_plane_t(t_plane pl, t_ray p_ray);
t_p		get_plane_val(t_ray p_ray, double t);

int		cylinder(t_cylinder *cy, t_ray p_ray, t_scene *scene);
int		cylinder_hit(t_cylinder cy, t_ray p_ray, double *, double *);
int		cylinder_check(t_cylinder *cy, t_ray p_ray, t_scene *, t_p rend_p);
double	get_cy_a(t_cylinder cy, t_ray p_ray);
double	get_cy_b(t_cylinder cy, t_ray p_ray);
double	get_cy_c(t_cylinder cy, t_ray p_ray);

int		cy_cap(t_cylinder cy, t_ray p_ray);
int		cy_cap_hit(t_cylinder cy, t_ray p_ray, t_p c_c);
t_p		get_c_c_top(t_cylinder cy);
t_p 	get_c_c_bottom(t_cylinder cy);

void	draw_rt(t_mlxdata *mlxdata, t_scene *scene);
void	save_distance(t_scene *scene, int type, t_p val, void *);

int		shoot_plane(t_scene *scene, t_ray p_ray);
int		shoot_cylinder(t_scene *scene, t_ray p_ray);
int		shoot_sphere(t_scene *scene, t_ray p_ray);

void	type_casting(t_obj, t_sphere **, t_plane **, t_cylinder **);
t_v		get_cy_normal(t_cylinder *, t_p);
t_v		cy_side_normal(t_cylinder *, t_p);
double	get_cy_side_t(t_cylinder *, t_p);

int		trgb(int, int, int, int);

void		parse(char *file, t_info *info);
int			name_valid(char *name);
void   		error_print(char *str);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);

char		*get_next_line(int fd);
char		*read_line(int fd, char *buffer, char **backup);
int			read_file(int fd, char *buffer, char **backup);
char		*separate_line(char **enterLine);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

void		init_info(t_info *info, t_scene *scene, t_mlxdata *mlxdata);
void	    init_mlxdata(t_mlxdata *mlxdata);
void    	init_scene(t_scene *scene);

void    	parse_line(char *line, t_info *info);
int			iswhitespace(char c);

int 		check_argument(char **split, int num);
void		parse_rgb(char *line, t_color *color);
double  	ft_atof(char *str);

char		**ft_split(char const *s, char c);
int			wordcnt(char const *s, char c);
size_t		ft_strlen_c(const char *s, char c);
char const	*str_jump(const char *s, char c);
void		strclear(char **s, unsigned int index);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);

void    	parse_point(char *line, t_p *point);
void    	parse_vector(char *line, t_v *vector);

void    	parse_ambient_light(char *line, t_amb *amb);
void		parse_camera(char *line, t_camera *cam);
void    	parse_light(char *line, t_light *light);
void    	parse_sphere(char *line, t_info *info);
void    	parse_cylinder(char *line, t_info *info);
void    	parse_plane(char *line, t_info *info);

t_sphere    *add_sphere(t_info *info);
t_cylinder  *add_cylinder(t_info *info);
t_plane     *add_plane(t_info *info);

void		free_array(char **str_array);
void    	free_info(t_info *info);

void    	print_argue(t_info *info);
int			key_hook(int, t_info);

void		shadow_ray_plane(t_ray *, t_scene *);
void		shadow_ray_sphere(t_ray *, t_scene *);
void		shadow_ray_cylinder(t_ray *ray, t_scene *);

#endif
