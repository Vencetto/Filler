/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:49:38 by vzomber           #+#    #+#             */
/*   Updated: 2018/08/13 13:49:40 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/ft_printf.h"
# include <stdbool.h>

typedef	struct		s_coords
{
			int		x;
			int		y;
			int		dist;
}					t_coords;

typedef	struct		s_map
{
		char		**map;
		int			map_x;
		int			map_y;
		char		**piece;
		t_coords	start;
		t_coords	end;
		char		m_symb;
		char		o_symb;
		int			neib;
}					t_map;

char				**ft_memforarr(char **arr, int x, int y);
void				check_player(t_map *map);
void				make_map(t_map *tools);
void				make_piece(t_map *tool, char *line);
void				fill_map(t_map *tool);
void				read_map_loop(t_map *tool);
void				algo(t_map *tool);
void				show_arr(char **arr);
void				algo(t_map *tool);
void				set_struct_0(t_map *tool);
bool				is_space(t_map *tool, int i, int j);
void				find_dist(t_map *tool, t_coords *xy, int i, int j);
void				figure_dist(t_map *tool, t_coords *enemy);
void				find_nearest(t_coords *enemy, t_map *tool, int i, int j);
int					distance(int x1, int y1, int x2, int y2);
void				find_start(t_map *tool);
bool				in_map(t_map *tool, int i, int j);
void				find_end(t_map *tool);

#endif
