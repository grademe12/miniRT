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
		free(info);
	}
	exit(0);
}

int	exit_rt(t_info *info)
{
	mlx_destroy_window(info->mlxdata->mlx, info->mlxdata->window);
	exit(0);
}