/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:54:57 by joloo             #+#    #+#             */
/*   Updated: 2025/08/19 14:37:45 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_background(void *param)
{
	t_data *data;

	data = (t_data *)param;
	data->frames++;
	handle_anim(data);
	handle_enemy(data);
	return (0);
}

void	handle_anim(t_data *data)
{
	if (data->frames % 10000 == 0)
	{
		data->anim_index = data->frames / 10000;
		if (data->last_move == 0)
			data->img['P'] = data->p_img_r[data->anim_index];
		else
			data->img['P'] = data->p_img_l[data->anim_index];
	}
	else
		return ;
	put_image(data, data->img['P'],
			data->player.x * PXL, data->player.y * PXL);
	if (data->frames == 30000)
		data->frames = -10000;
}
