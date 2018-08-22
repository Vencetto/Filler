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

int		distance(int x1, int y1, int x2, int y2)
{
	return (ft_abs(x2 - x1) + ft_abs(y2 - y1));
}

void	find_nearest(t_coords *enemy, t_map *tool)
{
	int		i;
	int		j;
	int		dist;
	int		b_dist;

	i = 0;
	b_dist = 999;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == tool->o_symb)
				dist = distance(i, j, tool->i, tool->j);
			if (dist <= b_dist)
			{
				b_dist = dist;
				enemy->x = i;
				enemy->y = j;
			}
			j++;
		}
		i++;
	}
}

t_coords ft_skip(char **piece, t_coords xy)
{
	int i;
	int	j;

	i = 0;
	while (piece[i])
	{
		j = 0;
		while (piece[i][j])
		{
			if (piece[i][j] == '*')
			{
				xy->x = i;
				xy->y - j;
				return (xy);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

void	figure_dist(t_map *tool, t_coords *enemy)
{
	int			tmp;
	int			x;
	int			y;
	t_coords	ij;

	x = tool->i;
	y = tool->j;
	tmp = ij.j;
	enemy->dist = 0;
	ij = ft_skip(tool->piece, &ij);
	while (tool->piece[ij.i])
	{
		ij.j = tmp;
		while (tool->piece[ij.i][ij.j])
		{
			if (tool->piece[ij.i][ij.j] == '*')
				enemy->dist += distance(ij.i, ij.j, enemy->x, enemy->y);
			ij.j++;
		}
		ij.i++;
	}
}

void	find_dist(t_map *tool, t_coords *xy)
{
	t_coords	enemy;

	find_nearest(&enemy, tool);
	figure_dist(tool, &enemy);
	if (xy->dist < enemy->dist)
	{
		xy->dist = enemy->dist;
		xy->x = enemy->x;
		xy->y = enemy->y;
	}
}
