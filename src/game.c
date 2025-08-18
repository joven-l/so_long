/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:04:07 by joloo             #+#    #+#             */
/*   Updated: 2025/08/18 16:29:06 by joloo            ###   ########.fr       */
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
	if (c == 'E' && data->coll == 0)
	{
		ft_printf("you win");
		free_exit(data, NULL, 0);
	}
	if (c == 'X')
	{
		ft_printf("you lose");
		free_exit(data, NULL, 0);
	}
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
	int		i;
	int		digit;

	str = ft_itoa(moves);
	i = 0;
	if (str == NULL)
		free_exit(data, "Error\nitoa fail\n", 1);
	while (str[i] != '\0')
	{
		digit = str[i] - '0';
		mlx_put_image_to_window(data->mlx, data->win,
			data->num[digit], i * 24, 24);
		i++;
	}
	free(str);
}
