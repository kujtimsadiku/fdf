/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:32:04 by ksadiku           #+#    #+#             */
/*   Updated: 2022/04/30 13:32:54 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	mouse_hook2(int key, t_data *data)
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