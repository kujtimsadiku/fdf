/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:25:40 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/19 16:27:00 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	additional_str(t_data *data)
{
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 210,
		0xFFFFFF, "Arrow left: trigger projections");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 230,
		0xFFFFFF, "C: changes the color");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 250,
		0xFFFFFF, "X: triggers the float");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 270,
		0xFFFFFF, "Z: untriggers the float");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 290,
		0xFFFFFF, "T: triggers DISCO!");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 310,
		0xFFFFFF, "Y: untriggers disco... :'(");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 370,
		0xFFFFFF, "ESC: quits");
}

void	put_string(t_data *data)
{
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 30,
		0xFFFFFF, "Keys Menu:");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 50,
		0xFFFFFF, "A S D W: moves it left, down, right & up");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 70,
		0xFFFFFF, "1 and 2: rotates the map \
		(only in one projc.) 1: increase 2: decrease");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 90,
		0xFFFFFF, "Minus '-': zoom out");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 110,
		0xFFFFFF, "Plus '+': zoom in");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 130,
		0xFFFFFF, "R: Reset the map position");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 150,
		0xFFFFFF, "Arrow up: increase 3D elevation");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 170,
		0xFFFFFF, "Arrow down: decrease 3D elevation");
	mlx_string_put(data->arg.mlx, data->arg.win, 30, 190,
		0xFFFFFF, "Arrow right: trigger projections");
	additional_str(data);
}
