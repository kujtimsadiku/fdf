#ifndef FDF2_H

# define FDF2_H

# include "libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "minilibx/mlx.h"

typedef struct	s_data
{
	int		rows;
	int		cols;
	int		color;
	int		gap;
	int		offset;
	int		elev;
	int		i;
	int		j;
	int		pz[2];
	int		z;
	int		x;
	int		y;
	double	geo;
	double	geo2;
	double	rotate;
	double	rotate2;
	int		trg;
	int		**map;
	void	*mlx;
	void	*win;
	int hold;
}				t_data;

# define WIDTH 1260
# define HEIGHT 720

void	read_map(char *file_name, t_data *data);
// void	draw_rows(t_data *data);
// void	draw_cols(t_data *data);
void	draw_map(t_data *data);
void	draw_line(t_data *data, int *px, int *py);
void	rotate(t_data *data, int *px, int *py, int *pz);
void	gap(t_data *data);
int		rgb_color(double r, double g, double b);
int		hot_keys(int key, t_data *data);
void	draw_map(t_data *data);
void	no_rotate2(t_data *data, int *px, int *py, int *pz);
void	no_rotate1(t_data *data, int *px, int *py, int *pz);


#endif
