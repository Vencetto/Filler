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

#include "../includes/filler.h"

int				distance(int x1, int y1, int x2, int y2)
{
	return (ft_abs(x2 - x1) + ft_abs(y2 - y1));
}

void			find_nearest(t_coords *enemy, t_map *tool, int x, int y)
{
	int			i;
	int			j;
	int			dist;

	i = -1;
	enemy->dist = 999;
	while (tool->map[++i])
	{
		j = -1;
		while (tool->map[i][++j])
		{
			if (tool->map[i][j] == tool->o_symb ||
				tool->map[i][j] == tool->o_symb + 32)
			{
				dist = distance(i, j, x, y);
				if (dist < enemy->dist)
				{
					enemy->dist = dist;
					enemy->x = i;
					enemy->y = j;
				}
			}
		}
	}
}

void			figure_dist(t_map *tool, t_coords *enemy, int i, int j)
{
	int			x;
	int			y;
	int			tmp;

	tmp = j;
	enemy->dist = 0;
	x = 0;
	while (x < tool->piece_x && i < tool->map_x)
	{
		j = tmp;
		y = 0;
		while (y < tool->piece_y && j < tool->map_y)
		{
			if (tool->piece[x][y] == '*')
				enemy->dist += distance(i, j, enemy->x, enemy->y);
			y++;
			i++;
		}
		x++;
		j++;
	}
}

void			find_dist(t_map *tool, t_coords *xy, int i, int j)
{
	t_coords	enemy;

	find_nearest(&enemy, tool, i, j);
	figure_dist(tool, &enemy, i, j);
	if (xy->dist > enemy.dist)
	{
		xy->dist = enemy.dist;
		xy->x = i;
		xy->y = j;
	}
}
