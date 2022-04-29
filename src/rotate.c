/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:10:49 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/29 15:46:55 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
	Rotate the map by calculating. With cos and sin we get the best results
	while calculating the degrees we can rotate and make 360 degree.
*/
void	rotate(t_data *data, double *px, double *py, double *pz)
{
	double	x[3];
	double	y[3];

	x[0] = px[0];
	x[1] = px[1];
	y[0] = py[0];
	y[1] = py[1];
	px[0] = (x[0] - y[0]) * cos(data->rotate);
	py[0] = (x[0] + y[0]) * sin(data->rotate) - (pz[0] * data->elev);
	px[1] = (x[1] - y[1]) * cos(data->rotate);
	py[1] = (x[1] + y[1]) * sin(data->rotate) - (pz[1] * data->elev);
}
