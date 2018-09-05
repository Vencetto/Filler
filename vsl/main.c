/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 20:18:54 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/04 20:18:55 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		fill_map(t_vsl *tool)
{
	char	*line = NULL;
	int		i;

	i = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Plateau"))
		{
			ft_strdel(&line);
			get_next_line(0, &line);
			break ;
		}
	}
	ft_strdel(&line);
	while (get_next_line(0, &line) && tool->map[i])
	{
		if (ft_strstr(line, "Piece"))
			break ;
		ft_strcpy(tool->map[i], line + 4);
		i++;
		ft_strdel(&line);
	}
	tool->map[i] = NULL;
	if (!line)
		return ;
	ft_strdel(&line);
}

static t_pnt	**ft_memforstruct(t_pnt **arr, int x, int y)
{
	int i;

	arr = (t_pnt **)ft_memalloc(sizeof(t_pnt*) * x);
	i = -1;
	while (++i < x)
		arr[i] = (t_pnt*)ft_memalloc(sizeof(t_pnt) * y);
	arr[i] = NULL;
	return (arr);
}

void		ft_get_size(t_vsl *tool)
{
	char	**tmp;
	char	*line = NULL;
	int		i;
	int		x;
	int		y;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Plateau"))
			break ;
		ft_strdel(&line);
	}
	tmp = ft_strsplit(line, ' ');
	x = ft_atoi(tmp[1]);
	y = ft_atoi(tmp[2]);
	tool->map_x = x;
	tool->map_y = y;
	tool->map = ft_memforarr(tool->map, x, y);
	tool->arr = ft_memforstruct(tool->arr, tool->map_x, tool->map_y);
	i = -1;
	while (tmp[++i])
		ft_strdel(&tmp[i]);
	free(tmp);
	ft_strdel(&line);
	ft_get_shift(tool);
}

void		visual(t_vsl *tool)
{
	fill_map(tool);
	split_map(tool);
	mlx_clear_window(tool->mlx, tool->win);
	draw_map(tool);
}

int			main(void)
{
	t_vsl	tool;

	ft_bzero(&tool, sizeof(tool));
	tool.mlx = mlx_init();
	tool.win = mlx_new_window(tool.mlx, W_HEIGHT, W_WIDTH, "filler");
	ft_get_size(&tool);
	visual(&tool);
	mlx_hook(tool.win, 17, 0, &just_exit, (void *)0);
	mlx_hook(tool.win, 2, 5, deal_key, &tool);
	mlx_loop(tool.mlx);
	return (0);
}