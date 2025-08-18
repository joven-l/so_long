/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:58:20 by joloo             #+#    #+#             */
/*   Updated: 2025/08/18 11:12:16 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_data *data, char *file)
{
	ft_memset(data, 0, sizeof(t_data));
	if (ft_strlen(file) <= 4)
		free_exit(data, "Error\nInvalid file\n", 1);
	if (ft_strncmp(file + (ft_strlen(file) - 4), ".ber", 4) != 0)
		free_exit(data, "Error\nNot a .ber file\n", 1);
	read_map(data, file);
	check_valid(data);
	check_path(data);
	init_mlx(data);
}

// removes newlines
void	read_map(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_exit(data, "Error\nError opening file\n", 1);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		data->map = ft_realloc_2d(&data->map, 0, i, i + 1);
		if (data->map == NULL)
			free_exit(data, "Error\nRealloc failure\n", 1);
		data->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	data->height = i;
	data->width = ft_strlen(data->map[0]);
	close(fd);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		free_exit(data, "Error\nmlx_init failed\n", 1);
	data->win = mlx_new_window(data->mlx, PXL * data->width,
			PXL * data->height, "so_long");
	if (data->win == NULL)
		free_exit(data, "Error\nmlx_new_window\n", 1);
	conv_textures(data);
	draw_map(data);
	display_moves(data, 0);
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->img[(int)data->map[i][j]], j * PXL, i * PXL);
			j++;
		}
		i++;
	}
	if (data->coll == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img['O'],
			data->exit.x * PXL, data->exit.y * PXL);
	}
}
