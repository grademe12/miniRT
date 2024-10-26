/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:48:35 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/26 17:10:34 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parse_ambient_light(char *line, t_amb *amb)
{
	char	**split;

	if (amb->flag == 1)
		error_print("Duplicate ambient light");
	split = ft_split(line, ' ');
	if (!(check_argument(split, 3)))
		error_print("Invalid argument amb");
	amb->r = ft_atof(split[1]);
	if (amb->r < 0 || amb->r > 1)
		error_print("Invalid ratio");
	parse_rgb(split[2], &amb->clr);
	free_array(split);
	amb->flag = 1;
}

void	parse_camera(char *line, t_camera *cam)
{
	char		**split;

	if (cam->flag == 1)
		error_print("Duplicate camera");
	split = ft_split(line, ' ');
	if (!(check_argument(split, 4)))
		error_print("Invalid argument cam");
	parse_point(split[1], &cam->camera_point);
	parse_vector(split[2], &cam->ctv_norm);
	cam->fov = ft_atoi(split[3]);
	if (cam->fov < 0 || cam->fov > 180)
		error_print("Invalid fov");
	free_array(split);
	cam->flag = 1;
}

void	parse_light(char *line, t_light *light)
{
	char **split;

	if (light->flag == 1)
		error_print("Duplicate light");
	split = ft_split(line, ' ');
	if (!(check_argument(split, 3)))
		error_print("Invalid argument light");
	parse_point(split[1], &light->origin);
	light->ratio = ft_atof(split[2]);
	if (light->ratio < 0 || light->ratio > 1)
		error_print("Invalid ratio");
	light->flag = 1;
	free_array(split);
}