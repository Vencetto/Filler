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

#include "../includes/filler.h"

int			make_map(t_map *tool)
{
	char	*line = NULL;
	char	**tmp;
	int		i;

	while ((tool->ret = get_next_line(0, &line)) > 0)
	{
		if (ft_strstr(line, "Plateau"))
			break ;
		ft_strdel(&line);
	}
	tmp = ft_strsplit(line, ' ');
	tool->map_x = ft_atoi(tmp[1]);
	tool->map_y = ft_atoi(tmp[2]);
	tool->map = ft_memforarr(tool->map, ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	i = -1;
	while (tmp[++i])
		ft_strdel(&tmp[i]);
	free(tmp);
	ft_strdel(&line);
	// show_arr(tool->map);
	return (1);
}

void			make_piece(t_map *tool, char *line)
{
	int		i;
	char	**tmp;
	int		p_x;
	int		p_y;

	tmp = ft_strsplit(line, ' ');
	p_x = ft_atoi(tmp[1]);
	p_y = ft_atoi(tmp[2]);
	tool->piece = ft_memforarr(tool->piece, p_x, p_y);
	tool->piece_x = p_x;
	tool->piece_y = p_y;
	i = -1;
	ft_strdel(&line);
	while (++i < p_x && (tool->ret = get_next_line(0, &line)) > 0)
	{
		ft_strcpy(tool->piece[i], line);
		ft_strdel(&line);
	}
	tool->piece[i] = NULL;
	i = -1;
	while (tmp[++i])
		ft_strdel(&tmp[i]);
	free(tmp);
//	show_arr(tool->piece);
}

void		fill_map(t_map *tool)
{
	char	*line = NULL;
	int		i;

	i = 0;

	tool->ret = get_next_line(0, &line);
	if (ft_strstr(line, "Plateau"))
	{
		ft_strdel(&line);
		tool->ret = get_next_line(0, &line);
	}
	ft_strdel(&line);
	while ((tool->ret = get_next_line(0, &line)) && tool->map[i])
	{
		if (ft_strstr(line, "Piece"))
			break ;
		ft_strcpy(tool->map[i], line + 4);
		i++;
		ft_strdel(&line);
	}
	tool->map[i] = NULL;
	// show_arr(tool->map);
	if (!line)
		return ;
		make_piece(tool, line);
}
