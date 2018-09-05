/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:34:54 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/05 13:34:56 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	make_point(int i, int j, t_vsl *tool)
{
	t_pnt	pnt;

	pnt.x = i * tool->dist;
	pnt.y = j * tool->dist;
	pnt.symb = tool->map[i][j];
	tool->arr[i][j] = pnt;
}

void	split_map(t_vsl *tool)
{
	int		i;
	int		j;

	i = -1;
	while (++i < tool->map_x)
	{
		j = -1;
		while (++j < tool->map_y)
		{
			dprintf(2, "%c", tool->map[i][j]);
			make_point(i, j, tool);
		}
		dprintf(2, "\n");
	}
}
