/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 15:18:34 by vzomber           #+#    #+#             */
/*   Updated: 2018/08/13 15:19:01 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

char	**ft_memforarr(int max, char **map)
{
	int i;

	map = (char**)malloc(sizeof(char*) * max);
	i = -1;
	while (i < max)
		map[++i] = (char*)malloc(sizeof(char) * max);
	map[i] = NULL;
	return (map);
}

char	check_player(void)
{
	char	*line = NULL;

	get_next_line(0, &line);
	if (ft_strstr(line, "vzomber"))
		return ('o');
	free(line);
	return ('x');
}

void	show_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		ft_putendl(arr[i]);
		i++;
	}
}

int		main(void)
{
	char	ch;
	char	**map;

	ch = check_player();
	// ft_printf("Player: %c\n", ch);
	map = make_map();
	read_map_loop(map);
	return (0);
}
