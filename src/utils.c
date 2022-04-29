/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:27:32 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/29 18:07:52 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
			data->clr.color = data->clr.b_color;
		else if (data->pz[0] < data->pz[1] || data->pz[0] > data->pz[1])
			data->clr.color = data->clr.b_color;
		else
			data->clr.color = data->clr.elev_color;
	}
}

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
	data->elev = 2;
	data->clr.color = 0xFFFFFF;
	data->trg = 1;
	data->rotate = 0.1;
	data->d = 0;
	data->flows = 0;
}