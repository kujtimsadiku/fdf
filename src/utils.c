/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:27:32 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/19 16:12:43 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	errors(int error, char *message)
{
	if (error == 0)
	{
		ft_putendl(message);
		exit(1);
	}
	else if (error == 1)
	{
		ft_putendl(message);
		exit(1);
	}
}

void	set_color(t_data *data, double *px, double *py)
{
	if (!data->flows)
	{
		if (data->pz[0] > data->pz[1] || data->pz[0] < data->pz[1])
			data->clr.color += data->clr.elev_color;
		else if (px[0] < px[1] || py[0] > py[1])
			data->clr.color = data->clr.elev_color;
		else if (data->pz[0] && data->pz[1])
			data->clr.color = data->clr.elev_color;
		else if (px[0] < py[0] || px[1] > py[1])
			data->clr.color = data->clr.elev_color;
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
	data->trigger = 0;
	data->rotate = 0.1;
	data->dir = 0;
	data->flows = 0;
	data->disco = 0;
}
