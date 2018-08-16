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

int		get_max(char *s1, char *s2)
{
	int max;

	if (!s1 || !s2)
		return (0);
	if (ft_strcmp(s1, s2) >= 0)
		max = ft_atoi(s1);
	else
		max = ft_atoi(s2);
	return (max);
}

char	**make_map(void)
{
	char	*line = NULL;
	char	**map = NULL;
	char	**tmp;
	int		max;

	max = 1;
	get_next_line(0, &line);
	// ft_printf("first str: %s\n", line);
	free(line);
	while (!ft_strstr(line, "Plateau"))
	{
		get_next_line(0, &line);
		// ft_printf("next str: %s\n", line);
		free(line);
	}
	// ft_printf("must be 'Plateau': %s\n", line);
	tmp = ft_strsplit(line, ' ');
	max = get_max(tmp[1], tmp[2]);
	map = ft_memforarr(max, map);
	// show_arr(map);
	// ft_printf("tmp[0]: %s tmp[1]: %s tmp[2]: %s \n", tmp[0], tmp[1], tmp[2]);
	// ft_printf("max: %d\n", max);
	return (map);
}

char	**make_piece(char **piece, char *line)
{
	int		i;
	char	**tmp;

	// ft_printf("must be 'Piece': %s\n", line);
	tmp = ft_strsplit(line, ' ');
	// ft_printf("tmp[0]: %s tmp[1]: %s tmp[2]: %s\n", tmp[0], tmp[1], tmp[2]);
	// ft_printf("max: %d\n", get_max(tmp[1], tmp[2]));
	piece = ft_memforarr(get_max(tmp[1], tmp[2]), piece);
	i = 0;
	free(line);
	while (get_next_line(0, &line) && (
		ft_strchr(line, '.') || ft_strchr(line, '*')))
	{
		ft_strcpy(piece[i], line);
		i++;
		free(line);
	}
	piece[i] = NULL;
	ft_printf("Piece:\n");
	show_arr(piece);
	return (piece);
}

char	**fill_map(char **map)
{
	char	*line = NULL;
	int		i;
	char	**piece = NULL;

	i = 0;
	while (get_next_line(0, &line) && !ft_strstr(line, "Piece") && map[i])
	{
		// ft_printf("line: %s, map[%d]: %s\t->\t", line, i, map[i]);
		ft_strcpy(map[i], line);
		// ft_printf("line: %s, map[%d]: %s\n",     line, i, map[i]);
		i++;
		free(line);
	}
	map[i] = NULL;
	ft_printf("Map:\n");
	show_arr(map);
	if (ft_strstr(line, "Piece"))
		piece = make_piece(piece, line);
	return (piece);
}

void	read_map_loop(char **map)
{
	char	**piece;
	char	*bf = NULL;

	while (read(0, bf, 1))
	{
		piece = fill_map(map);
		algo(map, piece);
	}
}