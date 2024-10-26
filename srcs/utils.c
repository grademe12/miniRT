/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:50:35 by woosupar          #+#    #+#             */
/*   Updated: 2024/10/26 16:53:41 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

char	*ft_strrchr(const char *s, int c)
{
	int	slen;

	slen = ft_strlen(s);
	s += slen;
	while (slen >= 0)
	{
		if ((unsigned char) *s == (unsigned char) c)
			return ((char *) s);
		slen--;
		s--;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if ((*s1 == '\0') || (*s2 == '\0'))
			return ((unsigned char) *s1 - (unsigned char) *s2);
		if ((unsigned char) *s1 != (unsigned char) *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

void	free_array(char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i])
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
}
