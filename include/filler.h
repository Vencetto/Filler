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

typedef	struct	s_coords
{
			int	*x;
			int	*y;
}				t_coords;

typedef	struct	s_map
{
		char	**map;
		char	**piece;
		char	m_symb;
		char	o_symb;
		int		i;
		int		j;
}				t_map;

char		**ft_memforarr(char **arr, int x, int y);
void		check_player(t_map *map);
void		make_map(t_map *tools);
void		make_piece(t_map *tool, char *line);
void		fill_map(t_map *tool);
void		read_map_loop(t_map *tool);
void		algo(t_map *tool);
void		show_arr(char **arr);

#endif
