/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woospark <woospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:02:23 by woosupar          #+#    #+#             */
/*   Updated: 2026/05/06 12:30:31 by woospark         ###   ########.fr       */
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

# ifndef OPEN_MAX
#  define OPEN_MAX 3000
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

typedef struct s_solution
{
	double	min;
	double	max;
	t_p		min_p;
	t_p		max_p;
	t_p		vals;
}				t_sol;

typedef struct s_cy_solution
{
	t_p	side_sol;
	t_p	cap_sol;
	t_p	min_p;
	t_p	max_p;
	t_p	rend_p;
}				t_cs;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_ray
{
	t_p	o;
	t_v	v;
}				t_ray;

typedef struct s_camera
{
	t_p	camera_point;
	t_v	ctv_norm;
	t_p	left_top;
	int	fov;
	int	flag;
}				t_camera;

typedef struct s_viewport
{
	double	width;
	double	height;
	double	ratio;
}			t_viewport;

typedef struct s_sphere
{
	t_p				sp_origin;
	double			sp_r;
	t_color			clr;
	struct s_sphere	*next;
}					t_sphere;

typedef struct s_plane
{
	t_p				op;
	t_v				n_vec;
	t_color			clr;
	struct s_plane	*next;
}				t_plane;

typedef struct s_cylinder
{
	double				cy_height;
	double				cy_r;
	t_p					cy_origin;
	t_color				clr;
	t_v					cy_nv;
	struct s_cylinder	*next;
}				t_cylinder;

typedef struct s_ambient
{
	double		r;
	t_color		clr;
	int			flag;
}				t_amb;

typedef struct s_light
{
	t_p		o;
	double	ratio;
	int		flag;
}			t_light;

typedef struct s_mlximg
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_len;
	int		endian;
}			t_mlximg;

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
	int		inside_flag;
}			t_obj;

typedef struct s_scene
{
	t_sphere	*sp;
	t_plane		*plane;
	t_cylinder	*cy;
	t_light		li;
	t_amb		amb;
	t_camera	cam;
	t_viewport	vp;
	t_obj		obj;
}			t_scene;

typedef struct s_info
{
	t_scene		*scene;
	t_mlxdata	*mlxdata;
}			t_info;

double		v_dot(t_v v1, t_v v2);
t_v			v_cross(t_v v1, t_v v2);
t_v			v_plus(t_v v1, t_v v2);
t_v			v_minus(t_v v1, t_v v2);
t_v			v_mul(t_v v, double a);
t_v			v_div(t_v v, double a);
double		v_len(t_v v);
t_v			v_norm(t_v v);
double		dis(t_p p1, t_p p2);
void		do_move(t_scene *scene, t_p set);
t_p			point_minus(t_p p1, t_p p2);

t_v			v_build(double x, double y, double z);
t_p			p_build(double x, double y, double z);
t_p			get_p(t_p a, t_v b, double c);
t_v			get_vec_two_points(t_p p1, t_p p2);

void		do_pixel(t_mlxdata *a, t_scene *b);
void		shoot_ray(t_scene *a, t_color *b);
void		pixel_shadow(t_color *a, t_obj b, t_scene *c);
void		pixel_light(t_color *a, t_obj b, t_scene *c);
void		pixel_nothing(t_color *a);

int			sphere(t_sphere *sp, t_ray ray, t_scene *scene);
int			sphere_val(t_sphere *a, t_ray b, double *c, double *d);
int			sphere_shadow(t_sphere *a, t_ray b, t_scene *c);

double		get_light_coef(t_scene scene, t_obj tmp);
double		diffuse_reflection(t_scene *scene, t_p val_p, t_obj tmp);
void		shadow_ray(t_scene *scene, t_ray *ray);
int			object_shadow(t_scene *scene);

int			plane(t_plane *pl, t_scene *scene, t_ray p_ray);
int			plane_check(t_v v, t_p p, t_p a);
int			check_par(t_plane pl, t_ray p_ray);
double		get_plane_t(t_plane pl, t_ray p_ray);

int			cylinder(t_cylinder *cy, t_ray p_ray, t_scene *scene);
int			cylinder_hit(t_cylinder b, t_ray a, t_scene *c, t_p *d);
int			cylinder_check(t_cylinder *cy, t_p rend_p);
double		get_cy_a(t_cylinder cy, t_ray p_ray);
double		get_cy_b(t_cylinder cy, t_ray p_ray);
double		get_cy_c(t_cylinder cy, t_ray p_ray);
int			define_side_sol(t_scene *a, t_ray b, t_p c, t_p *d);
int			cy_cap(t_cylinder d, t_ray c, t_scene *b, t_p *a);
int			cy_cap_hit(t_cylinder cy, t_ray p_ray, t_p c_c, double *a);

t_p			get_c_c_top(t_cylinder cy);
t_p			get_c_c_bottom(t_cylinder cy);

void		draw_rt(t_mlxdata *mlxdata, t_scene *scene);
void		save_distance(t_scene *scene, int type, t_p val, void *a);

int			shoot_plane(t_scene *scene, t_ray p_ray);
int			shoot_cylinder(t_scene *scene, t_ray p_ray);
int			shoot_sphere(t_scene *scene, t_ray p_ray);

void		type_casting(t_obj, t_sphere **a, t_plane **b, t_cylinder **c);
t_v			get_cy_normal(t_cylinder *a, t_p b);
t_v			cy_side_normal(t_cylinder *a, t_p b);
double		get_cy_side_t(t_cylinder *a, t_p b);

int			trgb(int a, int b, int c, int d);

void		parse(char *file, t_info *info);
int			name_valid(char *name);
void		error_print(char *str);
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
void		init_mlxdata(t_mlxdata *mlxdata);
void		init_scene(t_scene *scene);

void		parse_line(char *line, t_info *info);
int			iswhitespace(char c);

int			check_argument(char **split, int num);
void		parse_rgb(char *line, t_color *color);
double		ft_atof(char *str);
void		check_decimal(char *str, int *i, double *dec, double *res);

char		**ft_split(char const *s, char *c);
int			wordcnt(char const *s, char *c);
size_t		ft_strlen_c(const char *s, char *c);
char const	*str_jump(const char *s, char *c);
void		strclear(char **s, unsigned int index);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);

void		parse_point(char *line, t_p *point);
void		parse_vector(char *line, t_v *vector);

void		parse_ambient_light(char *line, t_amb *amb);
void		parse_camera(char *line, t_camera *cam);
void		parse_light(char *line, t_light *light);
void		parse_sphere(char *line, t_info *info);
void		parse_cylinder(char *line, t_info *info);
void		parse_plane(char *line, t_info *info);

t_sphere	*add_sphere(t_info *info);
t_cylinder	*add_cylinder(t_info *info);
t_plane		*add_plane(t_info *info);

void		free_array(char **str_array);

int			key_hook(int a, t_info *b);

void		shadow_ray_plane(t_ray *a, t_scene *b);
void		shadow_ray_sphere(t_ray *c, t_scene *d);
void		shadow_ray_cylinder(t_ray *ray, t_scene *a);
int			min(int a, int b);
int			exit_rt(t_info *a);
double		fmax(double a, double b);
double		fmin(double a, double b);
int			cylinder_shadow(t_cylinder *a, t_ray b, t_scene *c);
int			cylinder_shadow2(t_cylinder *a, t_ray b, t_scene *c, t_sol d);
void		mv_left_top(int a, int b, t_scene *c);
t_p			min_point(t_p a, t_p b, t_p c);
t_p			max_point(t_p a, t_p b, t_p c);
int			split_check(char a, char *b);

void		point_move(t_p *a, t_p b);
void		rotate_vector(t_v *a, t_v b, double c);
void		move_object(t_scene *a);
void		rotate_object(t_scene *a);
void		rotating(t_scene *a, t_v b, double c);
int			get_sphere_sol(t_sphere *sp, t_ray sh_ray, \
			t_scene *scene, t_sol *sol);

#endif
