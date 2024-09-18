/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:45:13 by woosupar          #+#    #+#             */
/*   Updated: 2024/09/19 02:07:26 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parse(char *file, t_info *info)
{
	int		fd;
	char	*line;
	(void) info;

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

void    parse_line(char *line, t_info *info)
{
    while (iswhitespace(*line))
        line++;
    if (ft_strncmp(line, "A", 1) == 0)
        parse_ambient_light(line, info);    
    else
         error_print("Invalid identifier");
    printf("ratio: %lf\n", info->scene->amb.ratio);
    printf("r: %d\n", info->scene->amb.a_color.r);
    printf("g: %d\n", info->scene->amb.a_color.g);
    printf("b: %d\n", info->scene->amb.a_color.b);
}