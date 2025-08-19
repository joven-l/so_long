/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:47:51 by joloo             #+#    #+#             */
/*   Updated: 2025/08/19 14:37:21 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check if clicked hit an enemy
void	find_enemy(t_data *data, int x, int y)
{
	t_enemy *node;
	t_enemy *prev;

	node = data->enemy;
	prev = NULL;
	while (node != NULL)
	{
		if (x >= node->pos.x * PXL &&
			x < (node->pos.x + 1) * PXL &&
			y >= node->pos.y * PXL &&
			y < (node->pos.y + 1) * PXL)
		{
			kill_enemy(data, node, prev);
			return ;
		}
		else
			prev = node;
		node = node->next;
	}
}

void	kill_enemy(t_data *data, t_enemy *node, t_enemy *prev)
{
	put_image(data, data->img['0'], node->pos.x * 64, node->pos.y * 64);
	data->map[node->pos.y][node->pos.x] = '0';
	if (prev == NULL)
		data->enemy = node->next;
	else
		prev->next = node->next;
	free(node);
}
// spread fire.
void	handle_enemy(t_data *data)
{
	t_enemy *node;
	int	i;

	node = data->enemy;
	i = 0;
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	node = data->enemy;
	while (i > 0)
	{
		spread_fire(data, node);
		node = node->next;
		i--;
	}
}

void	spread_fire(t_data *data, t_enemy *node)
{
	int	num;
	int	new_x;
	int	new_y;

	if (rand() % FIRE_RATE != 0)
		return ;
	num = rand() % 4;
	new_x = node->pos.x;
	new_y = node->pos.y;
	if (num == 0)
		new_x++;
	if (num == 1)
		new_x--;
	if (num == 2)
		new_y++;
	if (num == 3)
		new_y--;
	if (data->map[new_y][new_x] == '0')
	{
		add_enemy(data, new_x, new_y);
		data->map[new_y][new_x] = 'X';
		put_image(data, data->img['X'], new_x * 64, new_y * 64);
	}
	if (data->map[new_y][new_x] == 'P')
		free_exit(data, "You lose\n", 0);
}
