#include "../fdf.h"

/*---------Values set for x and y----------*/
static void row_values(t_data *data, int *px, int *py, int i)
{
	// px[0] = data->offset + (i * data->gap);
	// px[1] = data->offset + (i * data->gap) + data->gap;
	// py[0] = data->offset + (data->j * data->gap);
	// py[1] = data->offset + (data->j * data->gap);
	data->hold = i;
	if (data->trg)
		rotate(data, px, py, data->pz);
	else
		no_rotate1(data, px, py, data->pz);
}

/*-------------draws rows--------------*/
static void	draw_map2(t_data *data)
{
	int	px[3];
	int	py[3];
	int i;

	data->j = -1;
	while (++data->j < data->rows)
	{
		i = -1;
		while (++i < data->cols - 1)
		{
			if (data->map[data->j][i] > data->map[data->j][i + 1] || data->map[data->j][i] < data->map[data->j][i + 1])
			{
				data->pz[0] = data->map[data->j][i];
				data->pz[1] = data->map[data->j][i + 1];
			}
			else if (data->map[data->j][i])
			{
				data->pz[0] = data->map[data->j][i];
				data->pz[1] = data->map[data->j][i + 1];
			}
			else
			{
				data->pz[0] = data->map[data->j][i];
				data->pz[1] = data->map[data->j][i + 1];
			}
			row_values(data, px, py, i);
			draw_line(data, px, py);
		}
	}
}

static void col_values(t_data *data, int *px, int *py, int i)
{

	// px[0] = data->offset + (i * data->gap);
	// px[1] = data->offset + (i * data->gap);
	// py[0] = data->offset + (data->j * data->gap);
	// py[1] = data->offset + (data->j * data->gap) + data->gap;
	data->hold = i;
	if (data->trg)
		rotate(data, px, py, data->pz);
	else
		no_rotate2(data, px, py, data->pz);
}

void	draw_map(t_data *data)
{
	int	px[2];
	int	py[2];
	int i;

	data->j = -1;
	while (++data->j < data->rows - 1)
	{
		i = -1;
		while (++i < data->cols)
		{
			if (data->map[data->j][i] > data->map[data->j + 1][i] || data->map[data->j][i] < data->map[data->j + 1][i])
			{
				data->pz[0] = data->map[data->j][i];
				data->pz[1] = data->map[data->j + 1][i];
			}
			else if (data->map[data->j][i])
			{
				data->pz[0] = data->map[data->j][i];
				data->pz[1] = data->map[data->j + 1][i];
			}
			else
			{
				data->pz[0] = data->map[data->j][i];
				data->pz[1] = data->map[data->j + 1][i];
			}
			col_values(data, px, py, i);
			draw_line(data, px, py);
		}
	}
	draw_map2(data);
}