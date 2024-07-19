/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:48:02 by woosupar          #+#    #+#             */
/*   Updated: 2024/07/19 19:49:44 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main()
{
    int	i;
	int	j;
	double r;
	double g;
	double b;
	int		width;
	int		height;

	width = 256;
	height = 256;

	printf ("P3\n%d %d\n255\n", width, height);
	j = 255;
	while (j >= 0)
	{
		i = 0;
		while (i < width)
		{
			r = (double)i / (width - 1);
			g = (double)j / (height - 1);
			b = 0.25;
			printf ("%d %d %d\n", (int)(255.999 * r), (int)(255.999 * g), (int)(255.999 * b));
			++i;
		}
		--j;
	}
    return (0);
}
