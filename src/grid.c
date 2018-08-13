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

char	**ft_memformap(int max, char **map)
{
	int i;

	map = ft_memalloc(max);
	while (map[i])
	{
		map[i] = ft_memalloc(max);
		i++;
	}
	return (map);
}

char	**make_map(void)
{
	char	*line = NULL;
	char	*ptr;
	char	**map;
	char	**tmp;
	int		max;

	max = 1;
	get_next_line(0, &line);
	while (!(ptr = ft_strstr("Plateau", line)))
		get_next_line(0, &line);
	tmp = ft_strsplit(line, ' ');
	if (ft_strcmp(tmp[1], tmp[2]))
		max = ft_atoi(tmp[1]);
	else
		max = ft_atoi(tmp[2]);
	ft_memformap(max, map);
	return (map);
}

void	fill_map(char **map)
{
	char	*line = NULL;
	int		i;

	while (get_next_line(0, &line))
	{
		ft_strcpy(map[i], line);
		i++;
	}
}

int		read_map_loop(char **map)
{

}