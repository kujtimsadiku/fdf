/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:51:42 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/15 16:30:42 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		errors(0, "Usage: ./fdf <filename>");
	init(&data);
	read_map(argv[1], &data);
	data.arg.mlx = mlx_init();
	data.arg.win = mlx_new_window(data.arg.mlx, WIDTH, HEIGHT, "FDF Project");
	draw_map(&data);
	mlx_hook(data.arg.win, 2, 0L, &hot_keys, &data);
	mlx_hook(data.arg.win, 4, 0, mouse_hook, &data);
	mlx_loop(data.arg.mlx);
	sleep(15);
	return (0);
}
