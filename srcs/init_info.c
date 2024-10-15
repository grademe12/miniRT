#include "../miniRT.h"

void	init_info(t_info *info, t_scene *scene, t_mlxdata *mlxdata)
{
	info->scene = scene;
    info->mlxdata = mlxdata;
    init_mlxdata(info->mlxdata);
    init_scene(info->scene);
}

void    init_mlxdata(t_mlxdata *mlxdata)
{
    (void)  mlxdata;
    mlxdata->mlx = mlx_init();
    mlxdata->window = mlx_new_window(mlxdata->mlx, 800, 600, "Ray");
	mlxdata->mlximg = (t_mlximg *)malloc(sizeof(t_mlximg));
    mlxdata->mlximg->img = mlx_new_image(mlxdata->mlx, 800, 600);
}

void    init_scene(t_scene *scene)
{
    scene->sp = NULL;
    scene->plane = NULL;
    scene->cy = NULL;
    scene->amb.flag = 0;
    scene->light.flag = 0;
    scene->cam.flag = 0;
	scene->vp.height = 600;
	scene->vp.width = 800;
	scene->cam.viewport_h = 600;
	scene->cam.viewport_w = 800;
	scene->cam.left_top.x = -400;
	scene->cam.left_top.y = 300;
	scene->cam.left_top.z = 100;
}
