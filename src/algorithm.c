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

bool	lay_on(t_map *tool, int i, int j)
{
	int	tmp;
	int	x;
	int y;

	x = tool->i;
	y = tool->j;
	tmp = j;
	while (tool->piece[i])
	{
		j = tmp;
		while (tool->piece[i][j])
		{
			if (tool->piece[i][j] == '*')
			{
				tool->map[x + i][y + j] == tool->m_symb ? tool->neib++ : 0;
				if (!(tool->map[x + i][y + j] &&
					tool->map[x + i][y + j] != tool->o_symb))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_space(t_map *tool)
{
	int	i;
	int	j;

	i = 0;
	while (tool->piece[i])
	{
		j = 0;
		while (tool->piece[i][j])
		{
			if (tool->piece[i][j] == '*')
				return (lay_on(tool, i, j));
			j++;
		}
		i++;
	}
	return (false);
}

void	algo(t_map *tool)
{
	int			i;
	int			j;
	t_coords	xy;

	xy.dist = 10000;
	i = 0;
	while (tool->map[i])
	{
		j = 0;
		tool->i = i;
		while (tool->map[i][j])
		{
			tool->j = j;
			tool->neib = 0;
			if (is_space(tool) && tool->neib == 1)
				find_dist(tool, &xy);
			j++;
		}
		i++;
	}
	ft_printf("%d %d", xy.x, xy.y);
}
