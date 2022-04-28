#include "../fdf.h"

void	draw_line(t_data *data, int *px, int *py)
{
	double	deltaX = px[1] - px[0];
	double	deltaY = py[1] - py[0];
	int		pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	double	pixelX = px[0];
	double	pixelY = py[0];
	while (pixels)
	{
		if (data->pz[0] > data->pz[1] || data->pz[0] < data->pz[1])
			data->color = 0xF24F23;
		if (data->pz[0] == data->pz[1] && data->pz[0] && data->pz[1])
			data->color = 0xF24F23;
		else
			data->color = 0xFFFFFF;
		mlx_pixel_put(data->mlx, data->win, pixelX + (WIDTH / 2) + data->d, pixelY + (HEIGHT / 4), data->color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}