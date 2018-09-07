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

int		fill_map_2(t_vsl *tool)
{
	char	*line = NULL;
	int		i;

	i = 0;
	while (get_next_line(0, &line) && tool->map[i])
	{
		if (ft_strstr(line, "Piece"))
		{
			// add_info(tool, line);
			break ;
		}
		ft_strcpy(tool->map[i], line + 4);
		// dprintf(2, "%s\n", line + 4);
		i++;
		ft_strdel(&line);
	}
	tool->map[i] = NULL;
	if (!line)
		return (0);
	ft_strdel(&line);
	// dprintf(2, "\n");
	return (1);
}

int		fill_map(t_vsl *tool)
{
	char	*line = NULL;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Plateau"))
		{
			ft_strdel(&line);
			get_next_line(0, &line);
			break ;
		}
	}
	if (!line)
		return (0);
	ft_strdel(&line);
	fill_map_2(tool);
	return (1);
}

bool	ft_get_size(t_vsl *tool)
{
	char	**tmp;
	char	*line = NULL;
	int		i;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Plateau"))
			break;
		ft_strdel(&line);
	}
	if (!line)
		return (false);
	tmp = ft_strsplit(line, ' ');
	tool->map_x = ft_atoi(tmp[1]);
	tool->map_y = ft_atoi(tmp[2]);
	tool->map = ft_memforarr(tool->map, ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	i = -1;
	while (tmp[++i])
		ft_strdel(&tmp[i]);
	free(tmp);
	ft_strdel(&line);
	ft_get_shift(tool);
	return (true);
}

void		visual(t_vsl *tool)
{
	if (!fill_map(tool))
	{
		tool->score1 = 0;
		tool->score2 = 0;
		end_of_the_game(tool);
		return;
	}
	mlx_clear_window(tool->mlx, tool->win);
	draw_map(tool);
}

int			main(void)
{
	t_vsl	tool;

	ft_bzero(&tool, sizeof(tool));
	tool.mlx = mlx_init();
	tool.win = mlx_new_window(tool.mlx, W_HEIGHT, W_WIDTH, "filler");
	if (ft_get_size(&tool))
		visual(&tool);
	else
		return (0);
	mlx_hook(tool.win, 17, 0, &just_exit, (void *)0);
	mlx_hook(tool.win, 2, 5, deal_key, &tool);
	mlx_loop(tool.mlx);
	return (0);
}