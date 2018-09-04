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

#include "../includes/filler.h"

char	**ft_memforarr(char **arr, int x, int y)
{
	int i;

	arr = (char **)ft_memalloc(sizeof(char*) * (x + 1));
	i = -1;
	while (i < x)
		arr[++i] = (char*)ft_memalloc(sizeof(char) * (y + 1));
	return (arr);
}

void	check_player(t_map *tool)
{
	char	*line = NULL;

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

void	show_arr(char **arr)		//////////////	DELETE	//////////////
{
	int i;

	i = 0;
	while (arr[i])
	{
		dprintf(2, "LINE: %s\n",arr[i]);
		i++;
	}
}

int		main(void)
{
	t_map	tool;

	ft_bzero(&tool, sizeof(tool));
	check_player(&tool);
	make_map(&tool);

	while (1);
	// read_map_loop(&tool);
	return (0);
}

