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

char	**ft_memforarr(char **arr, int x, int y)
{
	int i;

	arr = (char **)malloc(sizeof(char*) * x + 1);
	i = -1;
	while (i < x)
		arr[++i] = (char*)malloc(sizeof(char) * y + 1);
	arr[++i] = NULL;
	return (arr);
}

void	check_player(t_map *tool)
{
	char	*line = NULL;

	get_next_line(0, &line);
	if (ft_strstr(line, "vzomber"))
	{
		tool->m_symb = 'O';
		tool->o_symb = 'X';
	}
	else
	{
		tool->m_symb = 'X';
		tool->o_symb = 'O';
	}
	free(line);
}

void	show_arr(char **arr)///////////////////////////
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
	t_map	tool;

	system("rm -rf log");
	set_struct_0(&tool);
	check_player(&tool);
	make_map(&tool);
	read_map_loop(&tool);
	return (0);
}
