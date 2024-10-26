/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:48:27 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/26 16:51:18 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parse_rgb(char *line, t_color *color)
{
	char	**split;

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

void	parse_point(char *line, t_p *point)
{
	char	**split;

	split = ft_split(line, ',');
	if (!(check_argument(split, 3)))
		error_print("Invalid argument in point");
	point->x = ft_atof(split[0]);
	point->y = ft_atof(split[1]);
	point->z = ft_atof(split[2]);
	free_array(split);
}

void	parse_vector(char *line, t_v *vector)
{
	char	**split;

	split = ft_split(line, ',');
	if (!(check_argument(split, 3)))
		error_print("Invalid argument in vector");
	vector->x = ft_atof(split[0]);
	vector->y = ft_atof(split[1]);
	vector->z = ft_atof(split[2]);
	free_array(split);
	if (vector->x < -1 || vector->x > 1)
		error_print("Invalid x vector");
	if (vector->y < -1 || vector->y > 1)
		error_print("Invalid y vector");
	if (vector->z < -1 || vector->z > 1)
		error_print("Invalid z vector");
}