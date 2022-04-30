/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:47:30 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/30 13:31:44 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_line(t_data *data, double *px, double *py)
{
	data->pxls.deltaX = px[1] - px[0];
	data->pxls.deltaY = py[1] - py[0];
	data->pxls.pixels = sqrt((data->pxls.deltaX * data->pxls.deltaX)
			+ (data->pxls.deltaY * data->pxls.deltaY));
	data->pxls.deltaX /= data->pxls.pixels;
	data->pxls.deltaY /= data->pxls.pixels;
	data->pxls.pixelY = py[0];
	data->pxls.pixelX = px[0];
	set_color(data);
	while (data->pxls.pixels)
	{
		set_color(data);
		mlx_pixel_put(data->arg.mlx, data->arg.win, data->pxls.pixelX
			+ (WIDTH / 2) + data->d, data->pxls.pixelY
			+ (HEIGHT / 4), data->clr.color);
		data->pxls.pixelX += data->pxls.deltaX;
		data->pxls.pixelY += data->pxls. deltaY;
		--data->pxls.pixels;
	}
}
