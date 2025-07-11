/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:57:40 by joloo             #+#    #+#             */
/*   Updated: 2025/07/11 15:44:42 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		write(2, "Invalid parameters\n", 19);
		exit(1);
	}
	init(&data, argv[1]);
	mlx_loop_hook(data.mlx, &handle_anim, &data);
	mlx_hook(data.win, 2, 1L << 0, &handle_input, &data);
	mlx_hook(data.win, 17, 0, &close_window, &data);
	mlx_loop(data.mlx);
}
