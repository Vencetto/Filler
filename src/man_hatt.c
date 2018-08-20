/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_hatt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:02:47 by vzomber           #+#    #+#             */
/*   Updated: 2018/08/18 16:02:49 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



t_cootds	find_min(char **map, int i, int j, t_coords *xy)
{
	int	x
	int	y;

	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{

			}
			j++;
		}
		i++;
	}
}

char	**man_hatt(char **map)
{
	int			i;
	int			j;
	t_coords	xy;

	i = 0;
	while (map[i])
	{
		j= 0;
		while (map[i][j])
		{
			if (map[i][j] == '.')
			{
				xy = find_min(map[i][j], i, j, &xy);
				map[i][j] = find_dist(i, j);
			}
			j++;
		}
		i++;
	}
	return (map);
}