/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:10:49 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/19 16:11:06 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection1(t_data *data, double *px, double *py, double *pz)
{
	double	*x;
	double	*y;

	x = px;
	y = py;
	*px = (*x - *y) * cos(data->rotate);
	*py = (*x + *y) * sin(data->rotate) - (*pz * data->elev);
	if (data->disco)
		*pz = (*x - *y) + *pz;
}

void	projection2(t_data *data, double *px, double *py, double *pz)
{
	double	*x;
	double	*y;

	x = px;
	y = py;
	*px = (*x - *y) / sqrt(2);
	*py = ((*x + (2 * *y)) - (*pz * data->elev)) / sqrt(6);
}
