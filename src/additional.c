/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:10:24 by vzomber           #+#    #+#             */
/*   Updated: 2018/08/27 18:10:25 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	set_struct_0(t_map *tool)
{
	tool->map = NULL;
	tool->piece = NULL;
	tool->map_x = 0;
	tool->map_y = 0;
	tool->m_symb = '0';
	tool->o_symb = '0';
	tool->neib = 0;
}

void	find_end(t_map *tool)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (tool->piece[i])
	{
		j = 0;
		while (tool->piece[i][j])
		{
			if (tool->piece[i][j] == '*')
			{
				(i > x) ? (x = i) : 0;
				(j > y) ? (y = j) : 0;
			}
			j++;
		}
		i++;
	}
	tool->end.x = x;
	tool->end.y = y;
}
