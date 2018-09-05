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
	int	dx;

	i = -1;
	dx = tool->sh_x;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			if (tool->arr[x][y].symb == 'o')
				mlx_pixel_put(tool->mlx, tool->win, tool->arr[x][y].x + i + dx,
				tool->arr[x][y].y + j + tool->sh_y, 0x0aff53);
			else if (tool->arr[x][y].symb == 'x')
				mlx_pixel_put(tool->mlx, tool->win, tool->arr[x][y].x + i + dx,
				tool->arr[x][y].y + j + tool->sh_y, 0xff0f0f);
		}
	}
	return (0);
}

int		draw_symb(t_vsl *tool, int x, int y)
{
	int	i;
	int	j;
	int	dx;

	dx = tool->sh_x;
	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			if (tool->arr[x][y].symb == 'X')
				mlx_pixel_put(tool->mlx, tool->win, tool->arr[x][y].x + i + dx,
				tool->arr[x][y].y + j + tool->sh_y, CLR1);
			else if (tool->arr[x][y].symb == 'O')
				mlx_pixel_put(tool->mlx, tool->win, tool->arr[x][y].x + i + dx,
				tool->arr[x][y].y + j + tool->sh_y, CLR2);
			else if (tool->arr[x][y].symb == 'o' || tool->arr[x][y].symb == 'x')
				return (help(tool, x, y));
			else
				mlx_pixel_put(tool->mlx, tool->win, tool->arr[x][y].x + i + dx,
				tool->arr[x][y].y + j + tool->sh_y, CLR3);
		}
	}
	return (0);
}

void	draw_map(t_vsl *tool)
{
	int	i;
	int j;

	i = -1;
	while (++i < 1)
	{
		j = -1;
		while (++j < tool->map_y)
			draw_symb(tool, i, j);
		dprintf(2, "x %d y %d\n", i, j);
	}
	mlx_string_put(tool->mlx, tool->win, 475, 50, 0x00ffcb, "Filler");
}

