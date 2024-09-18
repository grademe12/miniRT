#include "../miniRT.h"

void    parse_rgb(char *line, t_color *color)
{
    char    **split;

    split = ft_split(line, ',');
    if (!(check_argument(split, 3)))
        error_print("Invalid argument");
    color->r = ft_atoi(split[0]);
    color->g = ft_atoi(split[1]);
    color->b = ft_atoi(split[2]);
    if (color->r < 0 || color->r > 255) 
        error_print("Invalid R color");
    if (color->g < 0 || color->g > 255) 
        error_print("Invalid G color");
    if (color->b < 0 || color->b > 255) 
        error_print("Invalid B color");
    free_array(split);
}