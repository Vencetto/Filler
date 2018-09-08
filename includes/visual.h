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
# define PL1 0x910215
# define PL2 0x09842e
# define FONE 0x161616
# define NEW1 0x0aff53
# define NEW2 0xff0f0f

# include "../libft/includes/ft_printf.h"
# include "mlx.h"
# include <stdbool.h>

typedef struct	s_pnt
{
	int			x;
	int			y;
	char		symb;
}				t_pnt;

typedef	struct	s_vsl
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_x;
	int			map_y;
	int			sh_x;
	int			sh_y;
	int			dist;
	int			size;
	int			score1;
	int			score2;
}				t_vsl;

int				fill_map(t_vsl *tool);
bool			ft_get_size(t_vsl *tool);
void			visual(t_vsl *tool);
int				draw_symb(t_vsl *tool, int x, int y);
void			draw_map(t_vsl *tool);
int				just_exit(void *param);
int				deal_key(int key, t_vsl *tool);
void			ft_get_shift(t_vsl *tool);
int				help(t_vsl *tool, int x, int y);
void			end_of_the_game(t_vsl *tool);
void			show_arr(char **arr);

#endif
