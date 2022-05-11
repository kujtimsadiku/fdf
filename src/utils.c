/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:27:32 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/11 13:49:40 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(t_data *data)
{
	if (!data->flows)
	{
		if (data->pz[0] > data->pz[1] || data->pz[0] < data->pz[1])
			data->clr.color = data->clr.elev_color;
		else if (data->pz[0] < data->pz[1] || data->pz[0] > data->pz[1])
			data->clr.color = data->clr.elev_color;
		else if (data->pz[0] && data->pz[1])
			data->clr.color = data->clr.elev_color;
		else
			data->clr.color += data->clr.elev_color;
	}
	else if (data->flows)
	{
		if (data->pz[0] > data->pz[1] || data->pz[0] < data->pz[1])
			data->clr.color = rgb_color(0, 0, 0);
		else if (data->pz[0] < data->pz[1] || data->pz[0] > data->pz[1])
			data->clr.color = rgb_color(0, 0, 0);
		else
			data->clr.color = data->clr.elev_color;
	}
}

/*---------color rgb----------*/
int	rgb_color(double r, double g, double b)
{
	int		color;

	color = 0;
	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}

void	init(t_data *data)
{
	data->gap = 30;
	data->offset = 50;
	data->elev = 2;
	data->clr.color = 0xFFFFFF;
	data->trg = 0;
	data->rotate = 0.1;
	data->d = 0;
	data->flows = 0;
	data->iso.alpha = 0.15;
	data->iso.beta = 0.15;
	data->iso.gamma = 0.15;
}
