/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:54:41 by joloo             #+#    #+#             */
/*   Updated: 2025/08/15 13:54:41 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	conv_textures(t_data *data)
{
	data->img['C'] = convert_xpm(data, "./textures/coll.xpm");
	data->img['0'] = convert_xpm(data, "./textures/floor.xpm");
	data->img['1'] = convert_xpm(data, "./textures/wall.xpm");
	data->img['E'] = convert_xpm(data, "./textures/exit_closed.xpm");
	data->img['O'] = convert_xpm(data, "./textures/exit_open.xpm");
	data->img['X'] = convert_xpm(data, "./textures/enemy.xpm");
	data->num[0] = convert_xpm(data, "./textures/num_0.xpm");
	data->num[1] = convert_xpm(data, "./textures/num_1.xpm");
	data->num[2] = convert_xpm(data, "./textures/num_2.xpm");
	data->num[3] = convert_xpm(data, "./textures/num_3.xpm");
	data->num[4] = convert_xpm(data, "./textures/num_4.xpm");
	data->num[5] = convert_xpm(data, "./textures/num_5.xpm");
	data->num[6] = convert_xpm(data, "./textures/num_6.xpm");
	data->num[7] = convert_xpm(data, "./textures/num_7.xpm");
	data->num[8] = convert_xpm(data, "./textures/num_8.xpm");
	data->num[9] = convert_xpm(data, "./textures/num_9.xpm");
	conv_more(data);
}

void	conv_more(t_data *data)
{
	data->p_img[0] = convert_xpm(data, "./textures/player0.xpm");
	data->p_img[1] = convert_xpm(data, "./textures/player1.xpm");
	data->p_img[2] = convert_xpm(data, "./textures/player2.xpm");
	data->p_img[3] = convert_xpm(data, "./textures/player3.xpm");
	data->img['P'] = data->p_img[0];
}
