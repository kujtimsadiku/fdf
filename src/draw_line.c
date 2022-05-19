/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:47:30 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/19 14:47:37 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	data->pxls.deltax = px[1] - px[0];
	data->pxls.deltay = py[1] - py[0];
	data->pxls.pixels = sqrt((data->pxls.deltax * data->pxls.deltax)
			+ (data->pxls.deltay * data->pxls.deltay));
	data->pxls.deltax /= data->pxls.pixels;
	data->pxls.deltay /= data->pxls.pixels;
	data->pxls.pixely = py[0];
	data->pxls.pixelx = px[0];
	set_color(data, px, py);
	while (data->pxls.pixels)
	{
		set_color(data, px, py);
		if (data->flows)
			if (dont_draw(data))
				break ;
		mlx_pixel_put(data->arg.mlx, data->arg.win, data->pxls.pixelx
			+ (WIDTH / 2) + data->dir, data->pxls.pixely
			+ (HEIGHT / 4), data->clr.color);
		data->pxls.pixelx += data->pxls.deltax;
		data->pxls.pixely += data->pxls.deltay;
		--data->pxls.pixels;
	}
}
