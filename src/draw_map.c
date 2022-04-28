/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:10:57 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/28 12:58:46 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*---------Values set for x and y----------*/
void	row_values(t_data *data, int *px, int *py, int i)
{
	px[0] = data->offset + (i * data->gap);
	px[1] = data->offset + (i * data->gap) + data->gap;
	py[0] = data->offset + (data->j * data->gap);
	py[1] = data->offset + (data->j * data->gap);
	data->hold = i;
	if (data->trg)
		rotate(data, px, py, data->pz);
	// else
	// 	no_rotate1(data, px, py, data->pz);
}

/*-------------draws rows--------------*/
void	draw_map2(t_data *data)
{
	int	px[3];
	int	py[3];
	int	i;

	data->j = -1;
	while (++data->j < data->rows)
	{
		i = -1;
		while (++i < data->cols - 1)
		{
			row(data, px, py, i);
			draw_line(data, px, py);
		}
	}
}

void	col_values(t_data *data, int *px, int *py, int i)
{
	px[0] = data->offset + (i * data->gap);
	px[1] = data->offset + (i * data->gap);
	py[0] = data->offset + (data->j * data->gap);
	py[1] = data->offset + (data->j * data->gap) + data->gap;
	data->hold = i;
	if (data->trg)
		rotate(data, px, py, data->pz);
	// else
		// no_rotate2(data, px, py, data->pz);
}

void	draw_map(t_data *data)
{
	int	px[2];
	int	py[2];
	int	i;

	data->j = -1;
	while (++data->j < data->rows - 1)
	{
		i = -1;
		while (++i < data->cols)
		{
			col(data, px, py, i);
			draw_line(data, px, py);
		}
	}
	draw_map2(data);
}
