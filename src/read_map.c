/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:35:13 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/16 12:22:08 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*---Not even cols----- rivi 20-21 & 26-30 kusee*/
static void	map_even(t_data *data, char *line, int cols, int rows)
{
	char	**temp;

	temp = ft_strsplit(line, ' ');
	while (temp[cols])
		cols++;
	ft_free_array((void **)temp, (size_t)cols);
	data->previous_cols = data->map.cols;
	data->map.cols = cols;
	if (rows > 0)
		if (cols != data->previous_cols)
			errors(1, "Error. Cols are not even!");
	if (!data->map.cols)
		errors(1, "Invalid MAP_FILE!");
}

static void	get_map(char *file_name, t_data *data, int rows)
{
	char	*line;
	int		fd;

	rows = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		errors(1, "Error!");
	while (get_next_line(fd, &line))
	{
		map_even(data, line, 0, rows);
		ft_free((void *)line, ft_strlen(line));
		rows++;
	}
	data->map.rows = rows;
	free(line);
	close(fd);
}

static void	fill_the_map(int fd, int j, t_data *data)
{
	char	*line;
	char	**tmp;
	int		i;

	if (!(get_next_line(fd, &line)))
		errors(1, "Error!");
	tmp = ft_strsplit(line, ' ');
	if (!tmp)
		errors(1, "Error!");
	i = -1;
	while (tmp[++i])
		data->map.map[j][i] = ft_atoi(tmp[i]);
	ft_free_array((void **)tmp, (size_t)i);
	ft_free((void *)line, ft_strlen(line));
}

void	read_map(char *file_name, t_data *data)
{
	int		j;
	int		fd;

	get_map(file_name, data, 0);
	data->map.map = (int **)malloc(sizeof(int *) * (data->map.rows + 1));
	if (!(data->map.map))
		errors(1, "Error!");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		errors(1, "Error!");
	j = -1;
	while (++j < data->map.rows)
	{
		data->map.map[j] = (int *)malloc(sizeof(int) * (data->map.cols));
		if (!(data->map.map[j]))
			errors(1, "Error!");
		fill_the_map(fd, j, data);
	}
	close(fd);
}
