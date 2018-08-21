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

	tmp = 0;
	tool->tmp = tool->j;
	while (tool->piece[i])
	{
		tmp ? (j = 0) : 0;
		tmp ? (tool->j = tool->tmp) : 0;
		while (tool->piece[i][j])
		{
			if (tool->piece[i][j] == '*')
			{
				if (!(tool->map[tool->i][tool->j] &&
					tool->map[tool->i][tool->j] != tool->o_symb))
					return (false);
			}
			j++;
			tool->j++;
		}
		tmp = 1;
		tool->i++;
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
		while (tool->map[i][j])
		{
			if (tool->map[i][j] == tool->m_symb)
			{
				ft_printf("m_symb: %c\n", tool->m_symb);
				tool->i = i;
				tool->j = j;
				if (is_space(tool))// && no_enemy(tool) && one_contact(tool))
					ft_printf("yeah");//find_dist(tool, &xy); // if new_dist <= old_dist -> xy->dist = new_dist; xy->x = x_coord; xy->y = y_coord;
				else
					ft_printf("neah");
			}
			j++;
		}
		i++;
	}
	// ft_printf("%d %d", xy.x, xy.x);
}
