#include "../miniRT.h"

void    parse_ambient_light(char *line, t_info *info)
{
    char    **split;

    split = ft_split(line, ' ');
    if (!(check_argument(split, 3)))
        error_print("Invalid argument");
    info->scene->amb.ratio = ft_atof(split[1]);
    if (info->scene->amb.ratio < 0 || info->scene->amb.ratio > 1)
        error_print("Invalid ratio");
    parse_rgb(split[2], &info->scene->amb.a_color);
    free_array(split);
}