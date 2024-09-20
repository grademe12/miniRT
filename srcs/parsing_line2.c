#include "../miniRT.h"

void    parse_sphere(char *line, t_info *info)
{
    char        **split;
    t_sphere    *new_sp;

    new_sp = add_sphere(info);
    split = ft_split(line, ' ');
    if (!(check_argument(split, 4)))
        error_print("Invalid argument");
    parse_point(split[1], &new_sp->sp_origin);
    new_sp->sp_r = ft_atof(split[2]);
    if (new_sp->sp_r < 0)
        error_print("Invalid radius");
    parse_rgb(split[3], &new_sp->sp_color);
    free_array(split);
}

void    parse_plane(char *line, t_info *info)
{
    char        **split;
    t_plane     *new_pl;

    new_pl = add_plane(info);
    split = ft_split(line, ' ');
    if (!(check_argument(split, 4)))
        error_print("Invalid argument");
    parse_point(split[1], &new_pl->op);
    parse_vector(split[2], &new_pl->n_vec);
    parse_rgb(split[3], &new_pl->plane_color);
    free_array(split);
}

void    parse_cylinder(char *line, t_info *info)
{
    char        **split;
    t_cylinder  *new_cy;

    new_cy = add_cylinder(info);
    split = ft_split(line, ' ');
    if (!(check_argument(split, 6)))
        error_print("Invalid argument");
    parse_point(split[1], &new_cy->cy_origin);
    parse_vector(split[2], &new_cy->cy_nv);
    new_cy->cy_r = ft_atof(split[3]);
    if (new_cy->cy_r < 0)
        error_print("Invalid diameter");
    new_cy->cy_height = ft_atof(split[4]);
    if (new_cy->cy_height < 0)
        error_print("Invalid height");
    parse_rgb(split[5], &new_cy->cy_color);
    free_array(split);
}