/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:24:43 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/19 15:39:19 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

# define WIDTH 1980
# define HEIGHT 1280

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_map
{
	int		rows;
	int		cols;
	int		**map;
}				t_map;

typedef struct s_pixls
{
	double	deltax;
	double	deltay;
	double	pixely;
	double	pixelx;
	int		pixels;
}				t_pixls;

typedef struct s_color
{
	int		color;
	int		elev_color;
}				t_color;

typedef struct s_data
{
	t_mlx	arg;
	t_map	map;
	t_pixls	pxls;
	t_color	clr;
	int		gap;
	int		offset;
	int		elev;
	int		flows;
	int		i;
	int		j;
	int		dir;
	int		trg;
	int		disco;
	int		previous_cols;
	double	pz[2];
	double	rotate;
}				t_data;

void	read_map(char *file_name, t_data *data);
void	draw_map2(t_data *data);
void	draw_map(t_data *data);
void	draw_line(t_data *data, double *px, double *py);

void	init(t_data *data);
void	col_values(t_data *data, double *px, double *py, int i);
void	row_values(t_data *data, double *px, double *py, int i);
void	col(t_data *data, double *px, double *py, int i);
void	row(t_data *data, double *px, double *py, int i);
void	projection(t_data *data, double *px, double *py, double *pz);

void	set_color(t_data *data, double *px, double *py);
int		rgb_color(double r, double g, double b);

int		hot_keys(int key, t_data *data);
int		mouse_hook(int key, int x, int y, void *param);

void	put_string(t_data *data);
void	errors(int error, char *message);

#endif
