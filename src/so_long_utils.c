/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:04:27 by joloo             #+#    #+#             */
/*   Updated: 2025/08/19 13:34:22 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_exit(t_data *data, char *message, int exit_code)
{
	if (message != NULL)
		write(2, message, ft_strlen(message));
	free_img(data);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	if (data->mlx != NULL)
		free(data->mlx);
	ft_free_str_arr(data->map);
	exit(exit_code);
}

void	free_img(t_data *data)
{
	destroy_image(data, data->img['C']);
	destroy_image(data, data->img['0']);
	destroy_image(data, data->img['1']);
	destroy_image(data, data->img['E']);
	destroy_image(data, data->img['O']);
	destroy_image(data, data->img['X']);
	destroy_image(data, data->num[0]);
	destroy_image(data, data->num[1]);
	destroy_image(data, data->num[2]);
	destroy_image(data, data->num[3]);
	destroy_image(data, data->num[4]);
	destroy_image(data, data->num[5]);
	destroy_image(data, data->num[6]);
	destroy_image(data, data->num[7]);
	destroy_image(data, data->num[8]);
	destroy_image(data, data->num[9]);
	free_more_img(data);
}

void	free_more_img(t_data *data)
{
	destroy_image(data, data->p_img_r[0]);
	destroy_image(data, data->p_img_r[1]);
	destroy_image(data, data->p_img_r[2]);
	destroy_image(data, data->p_img_r[3]);
	destroy_image(data, data->p_img_l[0]);
	destroy_image(data, data->p_img_l[1]);
	destroy_image(data, data->p_img_l[2]);
	destroy_image(data, data->p_img_l[3]);
}
