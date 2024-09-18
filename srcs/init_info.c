#include "../miniRT.h"

void	init_info(t_info *info, t_scene *scene, t_mlxdata *mlxdata)
{
    info->scene = scene;
    info->mlxdata = mlxdata;
    // init_mlxdata(info->mlxdata);
    init_scene(info->scene);
}

void    init_mlxdata(t_mlxdata *mlxdata)
{
    (void)  mlxdata;
    // mlxdata->mlx = mlx_init();
    // mlxdata->window = mlx_new_window(mlxdata->mlx, 800, 600, "Ray");
    // mlxdata->mlximg = (t_mlximg *)malloc(sizeof(t_mlximg));
    // mlxdata->mlximg->img = mlx_new_image(mlxdata->mlx, 800, 600);
    // mlxdata->mlximg->addr = mlx_get_data_addr(mlxdata->mlximg->img, &mlxdata->mlximg->bit_per_pixel, &mlxdata->mlximg->line_len, &mlxdata->mlximg->endian);
}

void    init_scene(t_scene *scene)
{
    scene->sp = NULL;
    scene->plane = NULL;
    scene->cy = NULL;
    scene->light.origin.x = 0;
    scene->light.origin.y = 0;
    scene->light.origin.z = 0;
    scene->light.ratio = 0;
    scene->amb.ratio = 0;
    scene->amb.a_color.b = 0;
    scene->amb.a_color.g = 0;
    scene->amb.a_color.r = 0;
    scene->cam = NULL;
    scene->vp.height = 0;
    scene->vp.width = 0;
    scene->vp.ratio = 0;
    scene->obj.g_distance = 0;
    scene->obj.type = 0;
    scene->obj.val_p.x = 0;
    scene->obj.val_p.y = 0;
    scene->obj.val_p.z = 0;
    scene->obj.ptr = NULL;
}