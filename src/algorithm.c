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

	tmp = j;
	tool->tmp = tool->j;
	while (tool->piece[i] && tool->map[tool->i])
	{
		j =  tmp;
		tool->j = tool->tmp;
		while (tool->piece[i][j] && tool->map[tool->i][tool->j])
		{
			if (tool->piece[i][j] == '*')
			{
				ft_printf("%c", tool->map[tool->i][tool->j]);
				if (tool->map[tool->i][tool->j] == tool->m_symb)
					ft_printf("hey");
				tool->map[tool->i][tool->j] == tool->m_symb ? tool->neib++ : 0;
				if (tool->map[tool->i][tool->j] == tool->o_symb)
					return (false);
			}
			j++;
			tool->j++;
		}
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
int	k,l;
k = l = 0;
	xy.x = -12;
	xy.y = -12;
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
			if (is_space(tool))
				k++;
			if (tool->neib == 1)
				l++;
				// find_dist(tool, &xy);
			j++;
		}
		i++;
	}
	ft_printf("%d %d", k, l);
}
