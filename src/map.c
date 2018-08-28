/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 19:05:28 by vzomber           #+#    #+#             */
/*   Updated: 2018/08/13 19:05:29 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	make_map(t_map *tool)
{
	char	*line = NULL;
	char	**tmp;

	get_next_line(0, &line);
	free(line);
	while (!ft_strstr(line, "Plateau"))
	{
		get_next_line(0, &line);
		free(line);
	}
	tmp = ft_strsplit(line, ' ');
	tool->map_x = ft_atoi(tmp[1]);
	tool->map_y = ft_atoi(tmp[2]);
	tool->map = ft_memforarr(tool->map, ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	// show_arr(tool->map);
}

void	find_start(t_map *tool)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = 999;
	y = 999;
	while (tool->piece[i])
	{
		j = 0;
		while (tool->piece[i][j])
		{
			if (tool->piece[i][j] == '*')
			{
				i < x ? (x = i) : 0;
				j < y ? (y = j) : 0;
			}
			j++;
		}
		i++;
	}
	tool->start.x = x;
	tool->start.y = y;
	// tool->piece[tool->start.x][tool->start.y] = '#';
}

void	make_piece(t_map *tool, char *line)
{
	int		i;
	char	**tmp;

	tmp = ft_strsplit(line, ' ');
	tool->piece = ft_memforarr(tool->piece, ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	i = 0;
	free(line);
	system("echo '#'>>log");
	while (get_next_line(0, &line)
		&& (ft_strchr(line, '.') || ft_strchr(line, '*')))
	{
		system("echo '.'>>log");
		ft_strcpy(tool->piece[i], line);
		i++;
		free(line);
	}
		system("echo '?'>>log");
	tool->piece[i] = NULL;
		system("echo '!'>>log");
	find_start(tool);
	find_end(tool);
	// ft_printf("Piece:\n");
	// show_arr(tool->piece);
}

void	fill_map(t_map *tool)
{
	char	*line = NULL;
	int		i;

	i = 0;
	while (get_next_line(0, &line) && !ft_strstr(line, "Piece") && tool->map[i])
	{
		if (!ft_strchr(line, '.'))
		{
			free(line);
			get_next_line(0, &line);
		}
		ft_strcpy(tool->map[i], line + 4);
		i++;
		free(line);
	}
	tool->map[i] = NULL;
	// ft_printf("\nMap:\n");
	// show_arr(tool->map);
	if (ft_strstr(line, "Piece"))
		make_piece(tool, line);
}

void	read_map_loop(t_map *tool)
{
	char	*bf = NULL;

	while (read(0, bf, 1))
	{
		fill_map(tool);
		algo(tool);
	}
}
