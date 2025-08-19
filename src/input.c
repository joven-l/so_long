/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:04:09 by joloo             #+#    #+#             */
/*   Updated: 2025/08/19 14:44:07 by joloo            ###   ########.fr       */
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
	{
		data->last_move = 1;
		data->img['P'] = data->p_img_l[data->anim_index];
		move(data, -1, 0);
	}
	if (key == S || key == DOWN)
		move(data, 0, 1);
	if (key == D || key == RIGHT)
	{
		data->last_move = 0;
		data->img['P'] = data->p_img_r[data->anim_index];
		move(data, 1, 0);
	}
	return (0);
}

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free_exit(data, NULL, 0);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
	if (button == 1)
		find_enemy(data, x, y);
	return (0);
}
