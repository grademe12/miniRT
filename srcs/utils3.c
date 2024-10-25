#include "../miniRT.h"

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode == 53)
	{
		if (info->mlxdata->window)
			mlx_destroy_window(info->mlxdata->mlx, info->mlxdata->window);
		free(info->mlxdata->mlximg);
		free(info->scene->sp);
		free(info->scene->plane);
		free(info->scene->cy);
		free(info);
	}
	exit(0);
}

int	exit_rt(t_info *info)
{
	free(info->mlxdata->mlximg);
	free(info);
	free(info->scene->sp);
	free(info->scene->plane);
	free(info->scene->cy);
	mlx_destroy_window(info->mlxdata->mlx, info->mlxdata->window);
	exit(0);
}

t_v	fov_vector(int x, int y, t_scene *scene)
{
	t_v dir;

    float viewport_width = 2 * tan((fov / 2) * (M_PI / 180.0));
    float viewport_height = viewport_width * ((float)height / width);

    float pixel_size_x = viewport_width / width;
    float pixel_size_y = viewport_height / height;

    dir.x = (i - width / 2.0) * pixel_size_x;  // 중앙 기준 x 좌표
    dir.y = (height / 2.0 - j) * pixel_size_y;  // y좌표 상하 반전
    dir.z = 1;  // z축 기준으로 1 단위 거리
    float length = sqrt(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
    dir.x /= length;
    dir.y /= length;
    dir.z /= length;
    return dir;
}