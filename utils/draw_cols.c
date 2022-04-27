#include "../fdf.h"

static void col_values(t_data *data, int *px, int *py, int i)
{

	px[0] = data->offset + (i * data->gap);
	px[1] = data->offset + (i * data->gap);
	py[0] = data->offset + (data->j * data->gap);
	py[1] = data->offset + (data->j * data->gap) + data->gap;
	// if (data->trg)
	// 	rotate(data, px, py, data->pz);
	// rotate(&px[1], &py[1], data);
}

void	draw_cols(t_data *data)
{
	int	px[2];
	int	py[2];
	int i;

	data->j = -1;
	gap(data);
	while (++data->j < data->rows - 1)
	{
		i = -1;
		while (++i < data->cols)
		{
			if (data->map[data->j][i] > data->map[data->j + 1][i] || data->map[data->j][i] < data->map[data->j + 1][i])
			{
				data->pz[0] = data->map[data->j][i];
				data->pz[1] = data->map[data->j + 1][i];
				 // color if the current num is bigger then the lower row
			}
			// else if (data->map[data->j][i] < data->map[data->j + 1][i])
			// {
			// 	data->pz[0] = data->map[data->j][i];
			// 	data->pz[1] = data->map[data->j + 1][i];
			// // 	data->color /= data->map[data->j + 1][i]; // color if the lower col num is higher than the current 
			// }
			else if (data->map[data->j][i])
			{
				data->pz[0] = data->map[data->j][i];
				data->pz[1] = data->map[data->j + 1][i];
				// data->color *= data->map[data->j][i]; // color for 10 == 10
			}
			else
			{
				data->pz[0] = data->map[data->j][i];
				data->pz[1] = data->map[data->j + 1][i];
				// data->color = 0xFFFFFF;
			}
			col_values(data, px, py, i);
			draw_line(data, px, py);
		}
	}
}