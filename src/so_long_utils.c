/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:04:27 by joloo             #+#    #+#             */
/*   Updated: 2025/07/11 14:46:11 by joloo            ###   ########.fr       */
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
	if (data->img['1'] != NULL)
		mlx_destroy_image(data->mlx, data->img['1']);
	if (data->img['C'] != NULL)
		mlx_destroy_image(data->mlx, data->img['C']);
	if (data->img['0'] != NULL)
		mlx_destroy_image(data->mlx, data->img['0']);
	if (data->img['O'] != NULL)
		mlx_destroy_image(data->mlx, data->img['O']);
	if (data->img['E'] != NULL)
		mlx_destroy_image(data->mlx, data->img['E']);
	if (data->p_img[0] != NULL)
		mlx_destroy_image(data->mlx, data->p_img[0]);
	if (data->p_img[1] != NULL)
		mlx_destroy_image(data->mlx, data->p_img[1]);
	if (data->p_img[2] != NULL)
		mlx_destroy_image(data->mlx, data->p_img[2]);
	if (data->p_img[3] != NULL)
		mlx_destroy_image(data->mlx, data->p_img[3]);
	if (data->img['X'] != NULL)
		mlx_destroy_image(data->mlx, data->img['X']);
}

void	conv_more(t_data *data)
{
	int	i;

	data->p_img[0] = mlx_xpm_file_to_image(data->mlx,
			"./textures/player0.xpm", &i, &i);
	if (data->p_img[0] == NULL)
		free_exit(data, "Error\nFailed to conv player0.xpm\n", 1);
	data->p_img[1] = mlx_xpm_file_to_image(data->mlx,
			"./textures/player1.xpm", &i, &i);
	if (data->p_img[1] == NULL)
		free_exit(data, "Error\nFailed to conv player1.xpm\n", 1);
	data->p_img[2] = mlx_xpm_file_to_image(data->mlx,
			"./textures/player2.xpm", &i, &i);
	if (data->p_img[2] == NULL)
		free_exit(data, "Error\nFailed to conv player2.xpm\n", 1);
	data->p_img[3] = mlx_xpm_file_to_image(data->mlx,
			"./textures/player3.xpm", &i, &i);
	if (data->p_img[3] == NULL)
		free_exit(data, "Error\nFailed to conv player3.xpm\n", 1);
	data->img['X'] = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy.xpm", &i, &i);
	if (data->img['X'] == NULL)
		free_exit(data, "Error\nFailed to conv enemy.xpm\n", 1);
	data->img['P'] = data->p_img[0];
}
