/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:32:04 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/06 12:26:03 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
	that we can make the mouse_move work we need struct with the x, y and z cords
	we then need to create the right size map on the terminal.
	we need to know te previous x and y after that we give mouse x and y new ones
	the ones that are in parameters
*/

// int	mouse_move(int x, int y, void *param)
// {
// 	t_data *fdf;
// 	fdf = (t_data *)param;
	
// }

int mouse_hook(int key, int x, int y, void *param)
{
	t_data *data;
	data = (t_data *)param;
	
	(void)key;
	if (key == 4)
		data->gap += 10;
	else if (key == 5)
		if (data->gap != 0)
			data->gap -= 10;
	mlx_clear_window(data->arg.mlx, data->arg.win);
	draw_map(data);
	return 0;
}