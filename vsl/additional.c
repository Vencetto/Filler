/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:47:51 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/04 17:47:53 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		just_exit(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		deal_key(int key, t_vsl *tool)
{
	if (key == 53)
		just_exit((void *)0);
	else if (key == 49)
		visual(tool);
	// if (key == 'space')
		// make_all_stop();
	return (0);
}

void	ft_get_shift(t_vsl *tool)
{
	if (tool->map_y == 17)
	{
		tool->dist = 30;
		tool->sh_x = 0;
		tool->sh_y = 0;
	}
	if (tool->map_y == 40)
	{
		tool->dist = 20;
		tool->sh_x = 265;
		tool->sh_y = 105;
	}
	if (tool->map_y == 99)
	{
		tool->dist = 10;
		tool->sh_x = 0;
		tool->sh_y = 0;
	}
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
