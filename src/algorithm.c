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

int		check_piece(char ch)
{
	if (ch == '*')
		return (1);
	return (0);
}

int		n_check_map(t_map *tool)	// один раз своїх зачепив
{
	int	k;

	k = 0;
	if (tool->map[i][j] && tool->map[i][j] != tool->o_symb)
		k++;
	
}

void	check_map(t_map *tool)
{
	
}

void	try_put(t_map *tool)
{
	int m;
	int	n;

	m = 0;
	while (tool->piece[m])
	{
		while (tool->piece[m][n])
		{
			if (check_piece(tool->piece[m][n]))
				check_map(tool);
			n++;
		}
		m++;
	}
}

void	search_space(t_map *tool)
{
	int	i;
	int	j;

	i = 0;
	while (tool->map[i])
	{
		while (tool->map[i][j])
		{
			if (tool->map[i][j] == m_symb)
				try_put(tool);
			j++;
		}
		i++;
	}
}

void	algo(t_map *tool)
{
	// (void)tool;

	search_space(tool);
}
