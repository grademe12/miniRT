/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:45:13 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/25 20:50:39 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_scene	*parse(char *file)
{
	int		fd;
	char	*line;
	t_scene	*ret;

	fd = open(file, O_RDONLY);
	if (file == 0 || fd == -1)
		exit(1);
	line = get_next_line(fd);
	while (line != 0)
	{
		
	}
}