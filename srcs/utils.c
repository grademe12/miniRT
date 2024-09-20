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
	int i;

	i = 0;
	while (str_array[i])
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
}

void	free_info(t_info *info)
{
	t_sphere	*sp;
	// t_plane		*plane;
	// t_cylinder	*cy;

	while (info->scene->sp != NULL)
	{
		sp = info->scene->sp;
		info->scene->sp = info->scene->sp->next;
		free(sp);
	}
	// while (info->scene->plane != NULL)
	// {
	// 	plane = info->scene->plane;
	// 	info->scene->plane = info->scene->plane->next;
	// 	free(plane);
	// }
	// while (info->scene->cy != NULL)
	// {
	// 	cy = info->scene->cy;
	// 	info->scene->cy = info->scene->cy->next;
	// 	free(cy);
	// }
}