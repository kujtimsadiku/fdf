#include "../fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		j;

//	data->color = 0xFFFFFF;
	// data = (t_data *)malloc(sizeof(t_data));
/*	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 800, "FDF Project");*/
	if (argc != 2)
		return (0);
	//utils(data);
	else
	{
		read_map(argv[1], &data);
		i = 0;
		while (i < data.rows)
		{
			j = 0;
			while (j < data.cols)
			{
				printf("%3d ", data.map[i][j]);
				j++;
			}
			// ft_free((void **)data.map[i], (size_t)i);
			printf("\n");
			i++;
		}
		// free(data->map);
	}
	// free(data);
	system("leaks fdf");
	return (0);
}