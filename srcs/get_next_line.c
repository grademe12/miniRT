/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:02:41 by jaemikim          #+#    #+#             */
/*   Updated: 2024/09/17 02:20:56 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

char	*get_next_line(int fd)
{
	static char	*data_table[OPEN_MAX + 1];
	char		*buffer;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (data_table[fd] == NULL)
		data_table[fd] = ft_strdup("");
	line = read_line(fd, buffer, &data_table[fd]);
	free(buffer);
	buffer = NULL;
	return (line);
}

char	*read_line(int fd, char *buffer, char **backup)
{
	int		return_val;
	char	*return_line;

	return_val = read_file(fd, buffer, backup);
	if ((return_val == -1) || (**backup == '\0'))
	{
		free(*backup);
		*backup = NULL;
		return (NULL);
	}
	if (ft_strchr(*backup, '\n'))
		return (separate_line(backup));
	return_line = ft_strdup(*backup);
	free(*backup);
	*backup = NULL;
	return (return_line);
}

int	read_file(int fd, char *buffer, char **backup)
{
	int		bytes;
	char	*newbackup;

	bytes = 1;
	while (!(ft_strchr(*backup, '\n')) && (bytes != 0))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (bytes);
		buffer[bytes] = '\0';
		newbackup = *backup;
		*backup = ft_strjoin(newbackup, buffer);
		free(newbackup);
		newbackup = NULL;
	}
	return (bytes);
}

char	*separate_line(char **enterLine)
{
	char	*return_line;
	char	*temp;
	int		idx;

	idx = 0;
	while ((*enterLine)[idx] != '\n')
		idx++;
	temp = *enterLine;
	return_line = (char *) malloc(sizeof(char) * (idx + 2));
	ft_strlcpy(return_line, temp, idx + 2);
	*enterLine = ft_strdup(&temp[idx + 1]);
	free(temp);
	temp = NULL;
	return (return_line);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	dst += dstlen;
	while ((dstlen + i + 1 < dstsize) && (*src != '\0'))
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	if ((dstlen > dstsize) || (dstsize == 0))
		return (dstsize + srclen);
	else
		return (dstlen + srclen);
}
