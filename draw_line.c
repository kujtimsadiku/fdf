/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:47:30 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/05 14:38:33 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	dont_draw(t_data *data)
{
	if (data->pz[0] > data->pz[1])
		return (1);
	else if (data->pz[0] < data->pz[1])
		return (1);
	else
		return (0);
}

void	draw_line(t_data *data, double *px, double *py)
{
	// int start_y = py[0];
	// int start_x = px[0];
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
		if (data->flows)
			if (dont_draw(data))
				break ;
		mlx_pixel_put(data->arg.mlx, data->arg.win, data->pxls.pixelX
			+ (WIDTH / 2) + data->d, data->pxls.pixelY
			+ (HEIGHT / 4), data->clr.color);
		data->pxls.pixelX += data->pxls.deltaX;
		data->pxls.pixelY += data->pxls. deltaY;
		--data->pxls.pixels;
	}
}
