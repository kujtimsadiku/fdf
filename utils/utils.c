/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:27:32 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/26 23:52:29 by ksadiku          ###   ########.fr       */
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

void	gap(t_data *data)
{
	data->gap = 10;
	data->offset = 30;
	data->elev = 0;
	data->color = 0xFFFFFF;
	data->geo = 2;
	data->geo2 = 6;
	data->trg = 0;
	data->rotate = 1;
	data->rotate2 = 1;
}