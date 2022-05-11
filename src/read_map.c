/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:35:13 by ksadiku           #+#    #+#             */
/*   Updated: 2022/05/11 13:36:58 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_map(char *file_name, t_data *data, int rows, int cols)
{
	char	**temp;
	char	*line;
	int		fd;

	rows = 0;
	cols = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit (0);
	while (get_next_line(fd, &line))
	{
		if (rows == 0)
		{
			temp = ft_strsplit(line, ' ');
			while (temp[cols])
				cols++;
			ft_free_array((void **)temp, (size_t)cols);
		}
		ft_free((void *)line, ft_strlen(line));
		rows++;
	}
	data->map.rows = rows;
	data->map.cols = cols;
	free(line);
	close(fd);
}

static void	fill_the_map(int fd, int j, t_data *data)
{
	char	*line;
	char	**tmp;
	int		i;

	if (!(get_next_line(fd, &line)))
		exit (0);
	tmp = ft_strsplit(line, ' ');
	if (!tmp)
		exit (0);
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

	get_map(file_name, data, 0, 0);
	data->map.map = (int **)malloc(sizeof(int *) * (data->map.rows + 1));
	if (!(data->map.map))
		exit (0);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit (0);
	j = -1;
	while (++j < data->map.rows)
	{
		data->map.map[j] = (int *)malloc(sizeof(int) * (data->map.cols));
		if (!(data->map.map[j]))
			exit (0);
		fill_the_map(fd, j, data);
	}
	close(fd);
}
