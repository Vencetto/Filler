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


char	**ft_memforarr(int max, char **map);
char	check_player(void);
int		get_max(char *s1, char *s2);
char	**make_map(void);
char	**make_piece(char **piece, char *line);
char	**fill_map(char **map);
void		read_map_loop(char **map);
void	algo(char **map, char **piece);
void	show_arr(char **arr);

#endif
