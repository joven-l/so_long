/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:59:25 by joloo             #+#    #+#             */
/*   Updated: 2025/07/11 15:42:15 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "mlx.h"

# define PXL 64
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define ESC 65307

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_data
{
	int		e_count;
	int		c_count;
	int		p_count;
	char	**map;
	int		width;
	int		height;
	int		coll;
	int		moves;
	int		frames;
	t_pos	player;
	t_pos	exit;
	void	*mlx;
	void	*win;
	void	*img[128];
	void	*p_img[4];
}	t_data;

// game.c
void	move(t_data *data, int x, int y);
void	update_pos(t_data *data, int x, int y);
void	display_moves(t_data *data, int moves);

// init.c
void	init(t_data *data, char *file);
void	read_map(t_data *data, char *file);
void	init_mlx(t_data *data);
void	draw_img(t_data *data);
void	conv_textures(t_data *data);

// input.c
int		handle_input(int key, t_data *data);
int		close_window(void *param);
int		handle_anim(void *param);

// map.c
void	check_valid(t_data *data);
void	check_elements(t_data *data, int i, int j);
void	check_tile(t_data *data, int i, int j);
void	check_path(t_data *data);
void	flood_fill(t_data *data, char **map, int x, int y);

// so_long_utils.c
void	free_exit(t_data *data, char *message, int exit_code);
void	free_img(t_data *data);
void	conv_more(t_data *data);

#endif
