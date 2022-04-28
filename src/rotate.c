/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:10:49 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/28 16:02:24 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*-----sets hardcoded values-----*/

/*----set the map correctly and rotates it----*/
void	rotate(t_data *data, int *px, int *py, int *pz)
{
	int	x[3];
	int	y[3];
	int z[3];

	x[0] = px[0];
	x[1] = px[1];
	y[0] = py[0];
	y[1] = py[1];
	px[0] = ((x[0] - y[0]) * data->rotate_x) / sqrt(data->geo);
	py[0] = ((x[0] + ((data->rotate_x * y[0])) - (pz[0] * data->elev)) / sqrt(data->geo2));
	px[1] = ((x[1] - y[1]) * data->rotate_y) / sqrt(data->geo);
	py[1] = ((x[1] + ((data->rotate_y * y[1])) - (pz[1] * data->elev)) / sqrt(data->geo2));

	
	// y[0] = py[0];
	// y[1] = py[1];
	// x[0] = px[0];
	// x[1] = px[1];
	// z[0] = pz[0];
	// z[1] = pz[1];
	// px[0] = cos(y[0]) * x[0] + sin(y[0]) * z[0];
	// py[0] = -sin(y[0]) * x[0] + cos(y[0]) * z[0];
	// py[1] = cos(x[1]) * y[1] - sin(x[1]) * z[1];
	// px[1] = sin(x[1]) * y[1] + cos(x[1]) * z[1];
}

// void	rotate2(t_data *data. int *px, int *py, int *pz)
// {

// }