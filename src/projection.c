/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:10:49 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/16 15:11:30 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Rotate the map by calculating. With cos and sin we get the best results
	while calculating the degrees we can rotate and make 360 degree.
*/
void	projection(t_data *data, double *px, double *py, double *pz)
{
	double	*x;
	double	*y;
	double	*z;

	x = px;
	y = py;
	z = pz;
	*px = (*x - *y) * cos(data->rotate);
	*py = (*x + *y) * sin(data->rotate) - (*pz * data->elev);
	if (data->disco)
		*pz = (*x - *y) + *pz;
}
