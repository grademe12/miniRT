/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ppm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:02:14 by woosupar          #+#    #+#             */
/*   Updated: 2024/08/02 15:49:13 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.c"

void	render(t_viewport viewport)
{
	int	i;
	int	j;
	double	r;
	double	g;
	double	b;

	printf ("P3\n%d %d\n255\n", viewport.width, viewport.height);
	j = viewport.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < viewport.width)
		{
			r = (double)i / viewport.width - 1;
			g = (double)j / viewport.height - 1;
			b = 0.25;
			printf ("%d %d %d\n", (int)(255.999 * r), (int)(255.999 * g), (int)(255.999 * b));
			++i;
		}
		--j;
	}
}
