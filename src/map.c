/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:22:09 by joloo             #+#    #+#             */
/*   Updated: 2025/07/11 15:19:15 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_valid(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		if (ft_strlen(data->map[i]) != (size_t)data->width)
			free_exit(data, "Error\nMap inconsistent width\n", 1);
		check_elements(data, i, j);
		i++;
	}
	if (data->p_count != 1)
		free_exit(data, "Error\nNot 1 player\n", 1);
	if (data->e_count != 1)
		free_exit(data, "Error\nNot 1 exit\n", 1);
}

void	check_elements(t_data *data, int i, int j)
{
	if (i == 0 || i - 1 == data->height)
	{
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] != '1')
				free_exit(data, "Error\nMissing Wall\n", 1);
			j++;
		}
	}
	else
	{
		if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
			free_exit(data, "Error\nMissing Wall\n", 1);
		while (data->map[i][j] != '\0')
		{
			check_tile(data, i, j);
			j++;
		}
	}
}

void	check_tile(t_data *data, int i, int j)
{
	char	c;

	c = data->map[i][j];
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P' && c != 'X')
		free_exit(data, "Error\nInvalid tile\n", 1);
	if (c == 'C')
		data->coll++;
	if (c == 'E')
	{
		data->e_count++;
		data->exit.x = j;
		data->exit.y = i;
	}
	if (c == 'P')
	{
		data->p_count++;
		data->player.x = j;
		data->player.y = i;
	}
}

void	check_path(t_data *data)
{
	char	**copy;

	copy = ft_strarrdup(data->map);
	if (copy == NULL)
		free_exit(data, "Error\nft_strarrdup failure\n", 1);
	data->e_count = 0;
	flood_fill(data, copy, data->player.x, data->player.y);
	ft_free_str_arr(copy);
	if (data->e_count != 1)
		free_exit(data, "Error\nUnreachable exit\n", 1);
	if (data->c_count != data->coll)
		free_exit(data, "Error\nUnreachable coll\n", 1);
}

void	flood_fill(t_data *data, char **map, int x, int y)
{
	if (y < 0 || x < 0 || map[y] == NULL || map[y][x] == '\0')
		return ;
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		data->c_count++;
	if (map[y][x] == 'E')
		data->e_count++;
	map[y][x] = '1';
	flood_fill(data, map, x - 1, y);
	flood_fill(data, map, x + 1, y);
	flood_fill(data, map, x, y - 1);
	flood_fill(data, map, x, y + 1);
}
