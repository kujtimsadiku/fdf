/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:51:42 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/29 18:10:56 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void mouse_hook2(int key, t_data *data)
{
	if (key == 1)
		data->gap += 1;
	if (key == 2)
		data->gap -= 1;
}

int mouse_hook(int key, t_data *data)
{
	printf("%d\n", key);
	if (key >= 0)
		mouse_hook2(key, data);
	return (0);
}

void	hot_keys2(int key, t_data *data)
{
	if (key == 126)
		data->elev += 2;
	else if (key == 125)
		data->elev -= 2;
	else if (key == 24)
		data->gap += 1;
	else if (key == 27)
		data->gap -= 1;
	else if (key == 124)
		data->trg = 0;
	else if (key == 123)
		data->trg = 1;
	else if (key == 7)
		data->flows = 1;
	else if (key == 6)
		data->flows = 0;
	else if (key == 8)
	{
		data->clr.b_color += rgb_color(0, 0, 0);
		data->clr.elev_color += rgb_color(0.8, 0.2531, 0.2);
		data->clr.color += rgb_color(0.6, 0.92331, 0.7);
	}
	else if (key == 1)
		data->offset += 40;
	else if (key == 13)
		data->offset -= 40;
	else if (key == 0)
		data->d -= 20;
	else if (key == 2)
		data->d += 20;
	else if (key == 18)
	{
		data->rotate += 0.1;
		data->offset -= 1;
	}
	else if (key == 19)
	{
		data->rotate -= 0.1;
		data->offset += 1;
	}
	else if (key == 15)
		init(data);
	mlx_clear_window(data->arg.mlx, data->arg.win);
	draw_map(data);
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

	if (argc != 2)
		return (0);
	init(&data);
	read_map(argv[1], &data);
	data.arg.mlx = mlx_init();
	data.arg.win = mlx_new_window(data.arg.mlx, WIDTH, HEIGHT, "FDF Project");
	// draw_rows(&data);
	// draw_cols(&data);
	draw_map(&data);
	// mlx_string_put(data.arg.mlx, data.arg.win, 1100, 720, 0xFFFFFF, "Keys Menu");
	// mlx_string_put(data.arg.mlx, data.arg.win, 1100, 720, 0xFFFFFF, "left & right\
	//  	arrows: projection | +, - : size | up & down arrows: 3d elevation\
	//  	| C: colors | esc: exit");
	mlx_key_hook(data.arg.win, &hot_keys, &data);
	// mlx_mouse_hook(data.win, &mouse_hook, &data);
	mlx_loop(data.arg.mlx);
	return (0);
}
