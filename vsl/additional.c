/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:47:51 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/04 17:47:53 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	end_of_the_game(t_vsl *tool)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tool->map_x)
	{
		j = -1;
		while (++j < tool->map_y)
		{
			if (tool->map[i][j] == 'O' || tool->map[i][j] == 'O')
				tool->score1++;
			if (tool->map[i][j] == 'x' || tool->map[i][j] == 'x')
				tool->score2++;
		}
	}
	if (tool->score1 > tool->score2)
		mlx_string_put(tool->mlx, tool->win, 445, 100, PL2, "Player 1 won!");
	else if (tool->score1 < tool->score2)
		mlx_string_put(tool->mlx, tool->win, 445, 100, PL1, "Player 2 won!");
	else if (tool->score1 == tool->score2)
		mlx_string_put(tool->mlx, tool->win,
			445, 100, 0x00ffcb, "It's a draw!");
}

int		just_exit(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		deal_key(int key, t_vsl *tool)
{
	if (key == 53)
		just_exit((void *)0);
	else if (key == 49)
		visual(tool);
	return (0);
}

void	ft_get_shift(t_vsl *tool)
{
	if (tool->map_y == 17)
	{
		tool->dist = 30;
		tool->size = 15;
		tool->sh_x = 250;
		tool->sh_y = 250;
	}
	if (tool->map_y == 40)
	{
		tool->dist = 20;
		tool->size = 10;
		tool->sh_x = 220;
		tool->sh_y = 110;
	}
	if (tool->map_y == 99)
	{
		tool->dist = 8;
		tool->size = 5;
		tool->sh_x = 100;
		tool->sh_y = 100;
	}
}
