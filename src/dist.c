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

void			find_nearest(t_coords *enemy, t_map *tool)
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
				dist = distance(i, j, tool->i, tool->j);
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

t_coords		ft_skip(char **piece, t_coords *xy)
{
	int			i;
	int			j;

	i = 0;
	while (piece[i])
	{
		j = 0;
		while (piece[i][j])
		{
			if (piece[i][j] == '*')
			{
				xy->x = i;
				xy->y = j;
				return (*xy);
			}
			j++;
		}
		i++;
	}
	return (*xy);
}

t_coords		figure_dist(t_map *tool, t_coords *figure)
{
	int			tmp;
	int			x;
	int			y;
	t_coords	ij;
	t_coords	ret;

	x = tool->i;
	y = tool->j;
	tmp = ij.y;
	figure->dist = 0;
	ij = ft_skip(tool->piece, &ij);
	ret = ij;
	while (tool->piece[ij.x])
	{
		ij.y = tmp;
		while (tool->piece[ij.x][ij.y])
		{
			if (tool->piece[ij.x][ij.y] == '*')
				figure->dist += distance(ij.x, ij.y, figure->x, figure->y);
			ij.y++;
		}
		ij.x++;
	}
	return (ret);
}

void			find_dist(t_map *tool, t_coords *xy)
{
	t_coords	enemy;
	t_coords	shift;

	find_nearest(&enemy, tool);
	printf("#enemy# x %d, y %d, dist: %d\n",enemy.x, enemy.y, enemy.dist);
	shift = figure_dist(tool, &enemy);
	if (xy->dist > enemy.dist)
	{
		xy->dist = enemy.dist;
		xy->x = tool->i - shift.x;
		xy->y = tool->j - shift.y;
	}
}
