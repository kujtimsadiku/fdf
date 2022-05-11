/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:17:52 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/11 13:36:44 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	hot_keys3(int key, t_data *data)
{
	if (key == 2)
		data->d += 40;
	else if (key == 0)
		data->d	-= 40;
	else if (key == 18)
		data->rotate += 0.1;
	else if (key == 19)
		data->rotate -= 0.1;
	else if (key == 8)
	{
		data->clr.b_color += rgb_color(0, 0, 0);
		data->clr.elev_color += rgb_color(0.8, 0.2531, 0.2);
		data->clr.color += rgb_color(0.6, 0.92331, 0.7);
	}
	else if (key == 15)
		init(data);
	mlx_clear_window(data->arg.mlx, data->arg.win);
	draw_map(data);
}

static void	hot_keys2(int key, t_data *data)
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
	else if (key == 1)
	{
		data->offset += 40;
		data->d -= 40;
	}
	else if (key == 13)
	{
		data->offset -= 40;
		data->d += 40;
	}
	else
		hot_keys3(key, data);
	mlx_clear_window(data->arg.mlx, data->arg.win);
	draw_map(data);
}

/*------ printf("%d\n", key); -------*/
int	hot_keys(int key, t_data *data)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key >= 0 && key <= 129)
		hot_keys2(key, data);
	return (0);
}
