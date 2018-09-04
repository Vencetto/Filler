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

#include "../includes/filler.h"

bool	is_space(t_map *tool, int i, int j)
{
	int	tmp;
	int	x;
	int	y;

	tmp = j;
	x = -1;
	while (++x < tool->piece_x)
	{
		j = tmp;
		y = -1;
		while (++y < tool->piece_y)
		{
			if (tool->piece[x][y] == '*')
			{
				(tool->map[i][j] == tool->m_symb ||
				tool->map[i][j] == tool->m_symb + 32) ? tool->neib++ : 0;
				if (tool->map[i][j] == tool->o_symb ||
					tool->map[i][j] == tool->o_symb + 32)
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool		in_map(t_map *tool, int i, int j)
{
	if ((tool->piece_x + i < tool->map_x + 1) && (tool->piece_y + j < tool->map_y + 1))
		return (true);
	return (false);
}

void	algo(t_map *tool)
{
	int			i;
	int			j;
	t_coords	xy;

	xy.x = 0;
	xy.y = 0;
	xy.dist = 9999;
	i = 0;
	while (tool->map[i])
	{
		j = 0;
		while (tool->map[i][j])
		{
			tool->neib = 0;
			if ((in_map(tool, i, j)) && is_space(tool, i, j) && tool->neib == 1)
				find_dist(tool, &xy, i, j);
			j++;
		}
		i++;
	}
	ft_printf("%d %d\n", xy.x, xy.y);
}

void	read_map_loop(t_map *tool)
{
	while (42)
	{
		fill_map(tool);
		algo(tool);
		if (tool->ret != 1)
			break ;
		// dprintf(2, "%d\n", system("leaks vzomber.filler"));
		while (1);
	}
}
