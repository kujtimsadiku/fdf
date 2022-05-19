/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:32:04 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/19 14:42:58 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_hook(int key, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)y;
	(void)x;
	if (key == 4)
	{
		ft_putstr("Mouse pressed: ");
		ft_putnbr(key);
		ft_putchar('\n');
		data->offset -= 10;
		data->gap -= 5;
	}
	else if (key == 5)
	{
		ft_putstr("Mouse pressed: ");
		ft_putnbr(key);
		ft_putchar('\n');
		data->offset += 10;
		data->gap += 5;
	}
	mlx_clear_window(data->arg.mlx, data->arg.win);
	draw_map(data);
	return (0);
}
