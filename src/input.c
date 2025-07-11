/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:04:09 by joloo             #+#    #+#             */
/*   Updated: 2025/07/11 15:44:32 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int key, t_data *data)
{
	if (key == ESC)
		free_exit(data, NULL, 0);
	if (key == W || key == UP)
		move(data, 0, -1);
	if (key == A || key == LEFT)
		move(data, -1, 0);
	if (key == S || key == DOWN)
		move(data, 0, 1);
	if (key == D || key == RIGHT)
		move(data, 1, 0);
	return (0);
}

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free_exit(data, NULL, 0);
	return (0);
}

int	handle_anim(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->frames++;
	if (data->frames == 0 || data->frames == 10000 || data->frames == 20000)
	{
		data->img['P'] = data->p_img[data->frames / 10000];
		mlx_put_image_to_window(data->mlx, data->win, data->img['P'],
			data->player.x * PXL, data->player.y * PXL);
	}
	if (data->frames == 30000)
	{
		data->img['P'] = data->p_img[3];
		data->frames = -10000;
		mlx_put_image_to_window(data->mlx, data->win, data->img['P'],
			data->player.x * PXL, data->player.y * PXL);
	}
	return (0);
}
