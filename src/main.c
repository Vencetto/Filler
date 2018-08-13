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

char	check_player(void)
{
	char	*line = NULL;

	get_next_line(0, &line);
	if (ft_strstr(line, "vzomber"))
		return ('o');
	free(line);
	return ('x');
}

int		main(void)
{
	char	ch;
	char	**map;

	ch = check_player();
	map = make_map();
	read_map_loop(map);
	return (0);
}

	// char	*line = NULL;

	// while (get_next_line(0, &line))
	// {
	// 	ft_printf("%s\n", line);
	// 	free(line);
	// }