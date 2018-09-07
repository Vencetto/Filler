/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:20:31 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/05 13:20:32 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		help(t_vsl *tool, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tool->size)
	{
		j = -1;
		while (++j < tool->size)
		{
			if (tool->map[x][y] == 'o')
				mlx_pixel_put(tool->mlx, tool->win, y * tool->dist + j
					+ tool->sh_y, x * tool->dist + i + tool->sh_x, NEW1);
			else if (tool->map[x][y] == 'x')
				mlx_pixel_put(tool->mlx, tool->win, y * tool->dist + j
					+ tool->sh_y, x * tool->dist + i + tool->sh_x, NEW2);
		}
	}
	return (0);
}

int		draw_symb(t_vsl *tool, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tool->size)
	{
		j = -1;
		while (++j < tool->size)
		{
			if (tool->map[x][y] == 'X')
				mlx_pixel_put(tool->mlx, tool->win, y * tool->dist + j
					+ tool->sh_y, x * tool->dist + i + tool->sh_x, PL1);
			else if (tool->map[x][y] == 'O')
				mlx_pixel_put(tool->mlx, tool->win, y * tool->dist + j
					+ tool->sh_y, x * tool->dist + i + tool->sh_x, PL2);
			else if (tool->map[x][y] == 'o' || tool->map[x][y] == 'x')
				return (help(tool, x, y));
			else if (tool->map[x][y] == '.')
				mlx_pixel_put(tool->mlx, tool->win, y * tool->dist + j
					+ tool->sh_y, x * tool->dist + i + tool->sh_x, FONE);
		}
	}
	return (0);
}

void	draw_map(t_vsl *tool)
{
	int	i;
	int j;

	i = -1;
	while (++i < tool->map_x)
	{
		j = -1;
		while (++j < tool->map_y)
		{
			// dprintf(2, "x %d y %d\n", i, j);
			draw_symb(tool, i, j);
		}
	}
	mlx_string_put(tool->mlx, tool->win, 475, 50, 0x00ffcb, "Filler");
	mlx_string_put(tool->mlx, tool->win, 350, 70, 0x00ffcb, "Player 1 - green, player 2 - red!");
}

