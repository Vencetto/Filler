/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 13:56:36 by vzomber           #+#    #+#             */
/*   Updated: 2018/08/22 13:56:37 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int				distance(int x1, int y1, int x2, int y2)
{
	return (ft_abs(x2 - x1) + ft_abs(y2 - y1));
}

void			find_nearest(t_coords *enemy, t_map *tool, int x, int y)
{
	int			i;
	int			j;
	int			dist;

	i = 0;
	enemy->dist = 999;
	while (tool->map[i])
	{
		j = 0;
		while (tool->map[i][j])
		{
			if (tool->map[i][j] == tool->o_symb)
			{
				dist = distance(i, j, x, y);
				if (dist < enemy->dist)
				{
					enemy->dist = dist;
					enemy->x = i;
					enemy->y = j;
				}
			}
			j++;
		}
		i++;
	}
}

void		figure_dist(t_map *tool, t_coords *enemy)
{
	int			i;
	int			j;

	enemy->dist = 0;
	i = tool->start.x;
	while (i < tool->end.x)
	{
		j = tool->start.y;
		while (j < tool->end.y)
		{
			if (tool->piece[i][j] == '*')
				enemy->dist += distance(i, i, enemy->x, enemy->y);
			j++;
		}
		i++;
	}
}

void			find_dist(t_map *tool, t_coords *xy, int i, int j)
{
	t_coords	enemy;

	find_nearest(&enemy, tool, i, j);
	// printf("#enemy# x %d, y %d, dist: %d\n",enemy.x, enemy.y, enemy.dist);
	figure_dist(tool, &enemy);
	if (xy->dist > enemy.dist)
	{
		xy->dist = enemy.dist;
		xy->x = i - tool->start.x;
		xy->y = j - tool->start.y;
		// ft_printf("start: %d %d end: %d %d, i: %d j: %d\n", tool->start.x, tool->start.y, tool->end.x, tool->end.y, i, j);
	}
}
