/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:55:37 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/26 23:03:55 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*---------Values set for x and y----------*/
static void row_values(t_data *data, int *px, int *py, int i)
{
	px[0] = data->offset + (i * data->gap);
	px[1] = data->offset + (i * data->gap) + data->gap;
	py[0] = data->offset + (data->j * data->gap);
	py[1] = data->offset + (data->j * data->gap);
	// if (data->trg)
	// 	rotate(data, px, py, data->pz);
	// rotate(&px[1], &py[1], data);
}

/*-------------draws rows--------------*/
void	draw_rows(t_data *data)
{
	int	px[3];
	int	py[3];
	int i;

	data->j = -1;
	gap(data);
	while (++data->j < data->rows)
	{
		i = -1;
		while (++i < data->cols - 1)
		{
			if (data->map[data->j][i] > data->map[data->j][i + 1] || data->map[data->j][i] < data->map[data->j][i + 1])
			{
				data->pz[0] = data->map[data->j][i];
				data->pz[1] = data->map[data->j][i + 1];
				// data->color /= data->map[data->j][i];
			}
			// else if (data->map[data->j][i + 1] > data->map[data->j][i])
			// {
			// 	data->pz[0] = data->map[data->j][i];
			// 	data->pz[1] = data->map[data->j][i + 1];
			// 	// data->color *= data->map[data->j][i + 1];
			// }
			else if (data->map[data->j][i])
			{
				data->pz[0] = data->map[data->j][i];
				data->pz[1] = data->map[data->j][i + 1];
				// data->color /= data->map[data->j][i];
			}
			else
			{
				data->pz[0] = data->map[data->j][i];
				data->pz[1] = data->map[data->j][i + 1];
				// data->color = 0xFFFFFF;
			}
			row_values(data, px, py, i);
			draw_line(data, px, py);
		}
	}
}
