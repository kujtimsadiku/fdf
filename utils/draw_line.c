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
		// Cheange the color for this wiy a if statement.
		mlx_pixel_put(data->mlx, data->win, pixelX + 600, pixelY, data->color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}