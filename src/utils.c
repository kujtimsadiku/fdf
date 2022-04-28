/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:27:32 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/28 13:46:00 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*--------Hot keys--------*/
// static void	hot_keys2(t_data *data, int key)
// {
// 	if (key == 126)
// 		data->gap += 1;
// 	if (key == 125)
// 		data->gap -= 1;
// 	// if (key == 0)
// 	mlx_clear_window(data->mlx, data->win);
// 	draw_rows(data);
// 	draw_cols(data);
// }

// int	hot_keys(t_data *data, int key)
// {
// 	if (key >= 0 && key <= 129)
// 	 	hot_keys2(data, key);
// 	return (0);
// }

/*---------color rgb----------*/
int	rgb_color(double r, double g, double b)
{
	int		color;

	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}

void	init(t_data *data)
{
	data->gap = 30;
	data->offset = 50;
	data->elev = 0;
	data->color = 0xFFFFFF;
	data->geo = 2;
	data->geo2 = 6;
	data->trg = 1;
	data->rotate_x = 1;
	data->rotate_y = 1;
	data->d = 0;
}