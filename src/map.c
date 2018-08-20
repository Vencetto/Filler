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
	tool->map = ft_memforarr(tool->map, ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	// show_arr(tool->map);
}

void	make_piece(t_map *tool, char *line)
{
	int		i;
	char	**tmp;

	tmp = ft_strsplit(line, ' ');
	tool->piece = ft_memforarr(tool->piece, ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	i = 0;
	free(line);
	while (get_next_line(0, &line) &&
		(ft_strchr(line, '.') || ft_strchr(line, '*')))
	{
		ft_strcpy(tool->piece[i], line);
		i++;
		free(line);
	}
	tool->piece[i] = NULL;
	ft_printf("Piece:\n");
	show_arr(tool->piece);
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
	ft_printf("\nMap:\n");
	show_arr(tool->map);
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