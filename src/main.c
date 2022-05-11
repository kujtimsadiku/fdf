/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:51:42 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/11 13:32:27 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (0);
	init(&data);
	read_map(argv[1], &data);
	data.arg.mlx = mlx_init();
	data.arg.win = mlx_new_window(data.arg.mlx, WIDTH, HEIGHT, "FDF Project");
	draw_map(&data);
	// mlx_key_hook(data.arg.win, &hot_keys, &data);
	// mlx_mouse_hook(data.arg.win, &mouse_hook, &data);
	mlx_hook(data.arg.win, 2, 0L, &hot_keys, &data);
	mlx_hook(data.arg.win, 4, 0, mouse_hook, &data);
	mlx_loop(data.arg.mlx);
	return (0);
}
