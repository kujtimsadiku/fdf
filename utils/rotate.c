#include "../fdf.h"

/*-----sets hardcoded values-----*/

/*----set the map correctly and rotates it----*/
void	rotate(t_data *data, int *px, int *py, int *pz)
{
	int x[3];
	int y[3];

	x[0] = px[0];
	x[1] = px[1];
	y[0] = py[0];
	y[1] = py[1];

	px[0] = (x[0] - y[0]) / sqrt(data->geo);
	py[0] = ((x[0] + ((data->rotate * y[0])) - (pz[0] * data->elev)) / sqrt(data->geo2));

	px[1] = (x[1] - y[1]) / sqrt(data->geo);
	py[1] = ((x[1] + ((data->rotate2 * y[1])) - (pz[1] * data->elev)) / sqrt(data->geo2));
}

void	no_rotate1(t_data *data, int *px, int *py, int *pz)
{

	int x[4];
	int y[4];

	x[0] = px[0];
	x[1] = px[1];
	y[0] = py[0];
	y[1] = py[1];

	x[2] = px[0] / sqrt(data->geo);
	y[2] = (y[0] - pz[0] * data->elev) / sqrt(data->geo2);

	x[3] = px[1] / sqrt(data->geo);
	y[3] = (y[1] - pz[1] * data->elev) / sqrt(data->geo2);

	px[0] = data->offset + (data->hold * data->gap) + x[2];
	px[1] = data->offset + (data->hold * data->gap) + data->gap + x[3];
	py[0] = data->offset + (data->j * data->gap) + y[2];
	py[1] = data->offset + (data->j * data->gap) + y[3];
}

void	no_rotate2(t_data *data, int *px, int *py, int *pz)
{

	int x[4];
	int y[4];

	x[0] = px[0];
	x[1] = px[1];
	y[0] = py[0];
	y[1] = py[1];

	x[2] = px[0] / sqrt(data->geo);
	y[2] = (y[0] - pz[0] * data->elev) / sqrt(data->geo2);

	x[3] = px[1] / sqrt(data->geo);
	y[3] = (y[1] - pz[1] * data->elev) / sqrt(data->geo2);

	px[0] = data->offset + (data->hold * data->gap) + x[2];
	px[1] = data->offset + (data->hold * data->gap) + x[3];
	py[0] = data->offset + (data->j * data->gap) + y[2];
	py[1] = data->offset + (data->j * data->gap) + data->gap + y[3];
}