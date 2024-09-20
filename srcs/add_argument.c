#include "../miniRT.h"

t_sphere    *add_sphere(t_info *info)
{
    t_sphere    *new_sp;
    t_sphere    *tmp;

    tmp = info->scene->sp;
    new_sp = (t_sphere *)malloc(sizeof(t_sphere));
    if (new_sp == NULL)
        error_print("Malloc failed");
    new_sp->next = NULL;
    if (info->scene->sp == NULL)
        info->scene->sp = new_sp;
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_sp;
    }
    return (new_sp);
}

t_cylinder  *add_cylinder(t_info *info)
{
    t_cylinder  *new_cy;
    t_cylinder  *tmp;

    tmp = info->scene->cy;
    new_cy = (t_cylinder *)malloc(sizeof(t_cylinder));
    if (new_cy == NULL)
        error_print("Malloc failed");
    new_cy->next = NULL;
    if (info->scene->cy == NULL)
        info->scene->cy = new_cy;
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_cy;
    }
    return (new_cy);
}

t_plane     *add_plane(t_info *info)
{
    t_plane     *new_pl;
    t_plane     *tmp;

    tmp = info->scene->plane;
    new_pl = (t_plane *)malloc(sizeof(t_plane));
    if (new_pl == NULL)
        error_print("Malloc failed");
    new_pl->next = NULL;
    if (info->scene->plane == NULL)
        info->scene->plane = new_pl;
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_pl;
    }
    return (new_pl);
}