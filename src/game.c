/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:04:07 by joloo             #+#    #+#             */
/*   Updated: 2025/07/11 15:42:04 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *data, int x, int y)
{
	char	c;

	c = data->map[data->player.y + y][data->player.x + x];
	if (c == '1' || (c == 'E' && data->coll > 0))
		return ;
	if (c == 'C')
		data->coll--;
	if (data->coll == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img['O'],
			data->exit.x * PXL, data->exit.y * PXL);
	}
	if ((c == 'E' && data->coll == 0) || c == 'X')
		free_exit(data, NULL, 0);
	data->moves++;
	display_moves(data, data->moves);
	update_pos(data, x, y);
}

void	update_pos(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img['0'],
		data->player.x * PXL, data->player.y * PXL);
	data->map[data->player.y][data->player.x] = '0';
	data->player.x += x;
	data->player.y += y;
	mlx_put_image_to_window(data->mlx, data->win, data->img['P'],
		data->player.x * PXL, data->player.y * PXL);
	data->map[data->player.y][data->player.x] = 'P';
}

void	display_moves(t_data *data, int moves)
{
	char	*str;

	str = ft_itoa(moves);
	if (str == NULL)
		free_exit(data, "Error\nitoa fail\n", 1);
	mlx_put_image_to_window(data->mlx, data->win, data->img['1'], 0, 0);
	mlx_string_put(data->mlx, data->win, 16, 32, 0x00FFFFFF, str);
	free(str);
}
