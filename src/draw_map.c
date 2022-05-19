/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:10:57 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/19 16:16:56 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	row_values(t_data *data, double *px, double *py, int i)
{
	px[0] = data->offset + (i * data->gap);
	px[1] = data->offset + (i * data->gap) + data->gap;
	py[0] = data->offset + (data->j * data->gap);
	py[1] = data->offset + (data->j * data->gap);
	if (data->trigger == 1)
	{
		projection1(data, &px[0], &py[0], &data->pz[0]);
		projection1(data, &px[1], &py[1], &data->pz[1]);
	}
	else if (data->trigger == 2)
	{
		projection2(data, &px[0], &py[0], &data->pz[0]);
		projection2(data, &px[1], &py[1], &data->pz[1]);
	}
}

void	draw_map2(t_data *data)
{
	double	px[3];
	double	py[3];
	int		i;

	data->j = -1;
	while (++data->j < data->map.rows)
	{
		i = -1;
		while (++i < data->map.cols - 1)
		{
			row(data, px, py, i);
			draw_line(data, px, py);
		}
	}
}

void	col_values(t_data *data, double *px, double *py, int i)
{
	px[0] = data->offset + (i * data->gap);
	px[1] = data->offset + (i * data->gap);
	py[0] = data->offset + (data->j * data->gap);
	py[1] = data->offset + (data->j * data->gap) + data->gap;
	if (data->trigger == 1)
	{
		projection1(data, &px[0], &py[0], &data->pz[0]);
		projection1(data, &px[1], &py[1], &data->pz[1]);
	}
	if (data->trigger == 2)
	{
		projection2(data, &px[0], &py[0], &data->pz[0]);
		projection2(data, &px[1], &py[1], &data->pz[1]);
	}
}

void	draw_map(t_data *data)
{
	double	px[3];
	double	py[3];
	int		i;

	data->j = -1;
	while (++data->j < data->map.rows - 1)
	{
		i = -1;
		while (++i < data->map.cols)
		{
			col(data, px, py, i);
			draw_line(data, px, py);
		}
	}
	put_string(data);
	draw_map2(data);
}
