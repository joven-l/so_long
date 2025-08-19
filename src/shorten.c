/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shorten.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:23:13 by joloo             #+#    #+#             */
/*   Updated: 2025/08/19 11:21:53 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*convert_xpm(t_data *data, char *path)
{
	int		i;
	void	*ptr;

	ptr = mlx_xpm_file_to_image(data->mlx, path, &i, &i);
	if (ptr == NULL)
	{
		write(2, "Failed to convert ", 18);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		free_exit(data, NULL, 1);
	}
	return (ptr);
}

void	destroy_image(t_data *data, void *img)
{
	if (img != NULL)
		mlx_destroy_image(data->mlx, img);
}

void	put_image(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);	
}
