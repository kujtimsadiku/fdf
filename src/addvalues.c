/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addvalues.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:16:18 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/29 16:06:29 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	col(t_data *data, double *px, double *py, int i)
{
	if (data->map.map[data->j][i] > data->map.map[data->j + 1][i] ||
		data->map.map[data->j][i] < data->map.map[data->j + 1][i])
	{
		data->pz[0] = data->map.map[data->j][i];
		data->pz[1] = data->map.map[data->j + 1][i];
	}
	else if (data->map.map[data->j][i])
	{
		data->pz[0] = data->map.map[data->j][i];
		data->pz[1] = data->map.map[data->j + 1][i];
	}
	else
	{
		data->pz[0] = data->map.map[data->j][i];
		data->pz[1] = data->map.map[data->j + 1][i];
	}
	col_values(data, px, py, i);
}

void	row(t_data *data, double *px, double *py, int i)
{
	if (data->map.map[data->j][i] > data->map.map[data->j][i + 1] ||
		data->map.map[data->j][i] < data->map.map[data->j][i + 1])
	{
		data->pz[0] = data->map.map[data->j][i];
		data->pz[1] = data->map.map[data->j][i + 1];
	}
	else if (data->map.map[data->j][i])
	{
		data->pz[0] = data->map.map[data->j][i];
		data->pz[1] = data->map.map[data->j][i + 1];
	}
	else
	{
		data->pz[0] = data->map.map[data->j][i];
		data->pz[1] = data->map.map[data->j][i + 1];
	}
	row_values(data, px, py, i);
}

