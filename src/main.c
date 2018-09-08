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

#include "filler.h"

void	check_player(t_map *tool)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	if (ft_strstr(line, "p1"))
	{
		tool->m_symb = 'O';
		tool->o_symb = 'X';
	}
	else
	{
		tool->m_symb = 'X';
		tool->o_symb = 'O';
	}
	ft_strdel(&line);
}

int		main(void)
{
	t_map	tool;

	ft_bzero(&tool, sizeof(tool));
	check_player(&tool);
	make_map(&tool);
	read_map_loop(&tool);
	return (0);
}
