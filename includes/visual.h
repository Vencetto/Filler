/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 20:47:34 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/04 20:47:35 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# define W_HEIGHT 1000
# define W_WIDTH 1000
# define CLR1 0x910215
# define CLR2 0x09842e
# define CLR3 0x161616

# include "../libft/includes/ft_printf.h"
# include "mlx.h"

typedef struct	s_pnt
{
	int			x;
	int			y;
	char		symb;
}				t_pnt;

typedef	struct	s_vsl
{
		void	*mlx;
		void	*win;
		char	**map;
		int		map_x;
		int		map_y;
		t_pnt	**arr;
		int		sh_x;
		int		sh_y;
		int		dist;
}				t_vsl;


void		fill_map(t_vsl *tool);
void		ft_get_size(t_vsl *tool);
void		visual(t_vsl *tool);
int			draw_symb(t_vsl *tool, int x, int y);
void		draw_map(t_vsl *tool);
void		make_point(int i, int j, t_vsl *map);
void		split_map(t_vsl *tool);
int			just_exit(void *param);
int			deal_key(int key, t_vsl *tool);
void		ft_get_shift(t_vsl *tool);
int			help(t_vsl *tool, int x, int y);


void	show_arr(char **arr);

#endif