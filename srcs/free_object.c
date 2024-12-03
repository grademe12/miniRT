/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosupar <woosupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:10:49 by woosupar          #+#    #+#             */
/*   Updated: 2024/12/03 14:15:40 by woosupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	free_cylinder(t_cylinder *cy)
{
	t_cylinder	*cur;
	t_cylinder	*next;

	cur = cy;
	while (cur != 0)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}	
}

void	free_plane(t_plane *pl)
{
	t_plane	*cur;
	t_plane	*next;

	cur = pl;
	while (cur != 0)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
}

void	free_sphere(t_sphere *sp)
{
	t_sphere	*cur;
	t_sphere	*next;

	cur = sp;
	while (cur != 0)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
}
