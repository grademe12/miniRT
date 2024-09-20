#include "../miniRT.h"

void    print_argue(t_info *info)
{
    int i = 1;
 
    printf("-----------amb---------\n");
    printf("ratio: %lf\n", info->scene->amb.ratio);
    printf("r: %d\n", info->scene->amb.a_color.r);
    printf("g: %d\n", info->scene->amb.a_color.g);
    printf("b: %d\n", info->scene->amb.a_color.b);
    printf("-----------cam---------\n");
    printf("cam: %lf %lf %lf\n", info->scene->cam.camera_point.x, info->scene->cam.camera_point.y, info->scene->cam.camera_point.z);
    printf("ctv: %lf %lf %lf\n", info->scene->cam.ctv_norm.x, info->scene->cam.ctv_norm.y, info->scene->cam.ctv_norm.z);
    printf("fov: %d\n", info->scene->cam.fov);
    printf("-----------light---------\n");
    printf("origin: %lf %lf %lf\n", info->scene->light.origin.x, info->scene->light.origin.y, info->scene->light.origin.z);
    printf("ratio: %lf\n", info->scene->light.ratio);
    while (info->scene->sp != NULL)
    {
        printf("-----------sp%d---------\n", i++);
        printf("sp: %lf %lf %lf\n", info->scene->sp->sp_origin.x, info->scene->sp->sp_origin.y, info->scene->sp->sp_origin.z);
        printf("r: %lf\n", info->scene->sp->sp_r);
        printf("r: %d\n", info->scene->sp->sp_color.r);
        printf("g: %d\n", info->scene->sp->sp_color.g);
        printf("b: %d\n", info->scene->sp->sp_color.b);
        info->scene->sp = info->scene->sp->next;
    }
    i = 1;
    while (info->scene->plane != NULL)
    {
        printf("-----------pl%d---------\n", i++);
        printf("pl: %lf %lf %lf\n", info->scene->plane->op.x, info->scene->plane->op.y, info->scene->plane->op.z);
        printf("nv: %lf %lf %lf\n", info->scene->plane->n_vec.x, info->scene->plane->n_vec.y, info->scene->plane->n_vec.z);
        printf("r: %d\n", info->scene->plane->plane_color.r);
        printf("g: %d\n", info->scene->plane->plane_color.g);
        printf("b: %d\n", info->scene->plane->plane_color.b);
        info->scene->plane = info->scene->plane->next;
    }
    i = 1;
    while (info->scene->cy != NULL)
    {
        printf("-----------cy%d---------\n", i++);
        printf("cy: %lf %lf %lf\n", info->scene->cy->cy_origin.x, info->scene->cy->cy_origin.y, info->scene->cy->cy_origin.z);
        printf("nv: %lf %lf %lf\n", info->scene->cy->cy_nv.x, info->scene->cy->cy_nv.y, info->scene->cy->cy_nv.z);
        printf("r: %lf\n", info->scene->cy->cy_r);
        printf("h: %lf\n", info->scene->cy->cy_height);
        printf("r: %d\n", info->scene->cy->cy_color.r);
        printf("g: %d\n", info->scene->cy->cy_color.g);
        printf("b: %d\n", info->scene->cy->cy_color.b);
        info->scene->cy = info->scene->cy->next;
    }
}