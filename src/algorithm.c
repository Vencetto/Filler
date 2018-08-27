/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:48:56 by vzomber           #+#    #+#             */
/*   Updated: 2018/08/15 15:48:57 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

bool	is_space(t_map *tool, int i, int j)
{
	int	tmp;
	int	x;
	int	y;

	tmp = j;
	x = tool->start.x;
	y = tool->start.y;
	while (x < tool->end.x)
	{
		j = tmp;
		while (y < tool->end.y)
		{
			if (tool->piece[x][y] == '*')
			{
				// (tool->map[i][j] == tool->m_symb) ? tool->neib++ : 0;
				if (tool->map[i][j] == tool->m_symb)
					ft_printf("waat\n");
				if (tool->map[i][j] == tool->o_symb)
					return (false);
			}
			y++;
			j++;
		}
		x++;
		i++;
	}
	return (true);
}

bool		in_map(t_map *tool, int i, int j)
{
	if (((tool->end.x - tool->start.x + i) < tool->map_x)
		&& (tool->end.y - tool->start.y + j) < tool->map_y)
		return (true);
	return (false);
}

void	algo(t_map *tool)
{
	int			i;
	int			j;
	t_coords	xy;

	xy.x = -120;
	xy.y = -120;
	xy.dist = 9999;
	i = 0;
	while (tool->map[i])
	{
		j = 0;
		while (tool->map[i][j])
		{
			tool->neib = 0;
			if ((in_map(tool, i, j)) && is_space(tool, i, j))// && tool->neib == 1)
				find_dist(tool, &xy, i, j);
				ft_printf("%d %d ", xy.x, xy.y);
			j++;
		}
		i++;
	}
	ft_putnbr(xy.x);
	ft_putnbr(xy.y);
}
