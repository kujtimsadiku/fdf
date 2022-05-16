/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:32:04 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/16 15:04:57 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	that we can make the mouse_move work we need struct with the x, y and z cords
	we then need to create the right size map on the terminal.
	we need to know te previous x and y after that we give mouse x and y new ones
	the ones that are in parameters
*/

int	mouse_hook(int key, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)y;
	(void)x;
	if (key == 4)
	{
		data->offset -= 30;
		data->gap += 2;
	}
	else if (key == 5)
	{
		data->offset += 30;
		data->gap -= 2;
	}
	mlx_clear_window(data->arg.mlx, data->arg.win);
	draw_map(data);
	return (0);
}
