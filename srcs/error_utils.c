#include "../miniRT.h"

int	name_valid(char *name)
{
    char	*dot;

    dot = name;
    if (ft_strrchr(name, '/') != NULL)
    {
        dot = ft_strrchr(name, '/');
        dot++;
    }
    if (ft_strrchr(dot, '.') == NULL)
        return (1);
    dot = ft_strrchr(dot, '.');
    if ((ft_strncmp(dot, ".rt\0", 4) == 0) && (dot != name))
        return (0);
    return (1);
}

void    error_print(char *str)
{
    write(1, "Error\n", 6);
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
    exit(EXIT_FAILURE);
}