/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:49:27 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/29 00:38:21 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parse(char *file, t_info *info)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (file == 0 || fd == -1)
		error_print("Do not open file");
	line = get_next_line(fd);
	while (line != 0)
	{
		parse_line(line, info);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	parse_line(char *line, t_info *info)
{
	while (iswhitespace(*line))
		line++;
	if (ft_strncmp(line, "A", 1) == 0)
		parse_ambient_light(line, &info->scene->amb);
	else if (ft_strncmp(line, "C", 1) == 0)
		parse_camera(line, &info->scene->cam);
	else if (ft_strncmp(line, "L", 1) == 0)
		parse_light(line, &info->scene->li);
	else if (ft_strncmp(line, "sp", 2) == 0)
		parse_sphere(line, info);
	else if (ft_strncmp(line, "pl", 2) == 0)
		parse_plane(line, info);
	else if (ft_strncmp(line, "cy", 2) == 0)
		parse_cylinder(line, info);
	else
		error_print("Invalid identifier");
}
