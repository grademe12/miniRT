/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jammin <jammin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:56:54 by jaemikim          #+#    #+#             */
/*   Updated: 2024/09/17 02:21:19 by jammin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char) *s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if ((unsigned char) c == 0)
		return ((char *) s);
	else
		return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*tmp;

	if (!s1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	tmp = str;
	while (*s1 != '\0')
	{
		*str = *s1;
		str++;
		s1++;
	}
	*str = '\0';
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*str;

	if ((!s1) && (!s2))
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (s1len + s2len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, s1len + 1);
	ft_strlcat(str, (char *) s2, s2len + s1len + 1);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while ((i + 1 < dstsize) && (*src != '\0'))
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	if (dstsize != 0)
		*dst = '\0';
	while (*src != '\0')
	{
		i++;
		src++;
	}
	return (i);
}
