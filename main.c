/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:51:42 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/26 23:44:25 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	hot_keys2(int key, t_data *data)
{
	if (key == 126)
		data->elev += 2;
	if (key == 125)
		data->elev -= 2;
	if (key == 24)
		data->gap += 1;
	if (key == 27)
		data->gap -= 1;
	if (key == 124)
		data->trg = 0;
	if (key == 123)
		data->trg = 1;
	if (key == 8)
		data->color *= 2;
	if (key == 0)
		data->offset += 10;
	if (key == 1)
		data->offset -= 10;
	if (key == 45)
	{
		data->geo += 0.33;
		printf("%f\n", data->geo);
	}
	if (key == 46)
	{
		data->geo2 += 2.2;
		printf("%f\n", data->geo2);
	}
	if (key == 47)
	{
		data->geo -= 0.33;
		printf("%f\n", data->geo);
	}
	if (key == 44)
	{
		data->geo2 -= 2.2;
		printf("%f\n", data->geo2);
	}
	if (key == 18)
		data->rotate += 0.2;
	if (key == 19)
		data->rotate -= 0.2;
	if (key == 20)
		data->rotate2 -= 0.2;
	if (key == 21)
		data->rotate2 += 0.2;

	
	// if (key == 0)
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	// draw_rows(data);
	// draw_cols(data);
}

int	hot_keys(int key, t_data *data)
{
	printf("%d\n", key);
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key >= 0 && key <= 129)
	 	hot_keys2(key, data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		j;

	if (argc != 2)
		return (0);
	gap(&data);
	read_map(argv[1], &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FDF Project");
	// draw_rows(&data);
	// draw_cols(&data);
	draw_map(&data);
	// mlx_string_put(data.mlx, data.win, 1100, 720, 0xFFFFFF, "Keys Menu");
	// mlx_string_put(data.mlx, data.win, 1100, 720, 0xFFFFFF, "left & right\
	//  	arrows: projection | +, - : size | up & down arrows: 3d elevation\
	//  	| C: colors | esc: exit");
	mlx_key_hook(data.win, &hot_keys, &data);
	mlx_loop(data.mlx);
	return (0);
}
