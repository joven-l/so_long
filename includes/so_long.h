/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:59:25 by joloo             #+#    #+#             */
/*   Updated: 2025/08/19 14:36:51 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "mlx.h"
# include "time.h"

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
# define FIRE_RATE 100000

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_enemy
{
	t_pos	pos;
	struct s_enemy	*next;
}	t_enemy;

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
	int		last_move;
	int		anim_index;
	t_pos	player;
	t_pos	exit;
	t_enemy	*enemy;
	void	*mlx;
	void	*win;
	void	*img[128];
	void	*p_img_r[4];
	void	*p_img_l[4];
	void	*num[10];
}	t_data;

// background.c
int		handle_background(void *param);
void	handle_anim(t_data *data);

// conv_sprites.c
void	conv_textures(t_data *data);
void	conv_more(t_data *data);

// enemy.c
void	find_enemy(t_data *data, int x, int y);
void	kill_enemy(t_data *data, t_enemy *node, t_enemy *prev);
void	handle_enemy(t_data *data);
void	spread_fire(t_data *data, t_enemy *node);

// game.c
void	move(t_data *data, int x, int y);
void	update_pos(t_data *data, int x, int y);
void	display_moves(t_data *data, int moves);

// init.c
void	init(t_data *data, char *file);
void	read_map(t_data *data, char *file);
void	init_mlx(t_data *data);
void	draw_map(t_data *data);
void	add_enemy(t_data *data, int x, int y);

// input.c
int		handle_input(int key, t_data *data);
int		close_window(void *param);
int		handle_mouse(int button, int x, int y, t_data *data);

// map.c
void	check_valid(t_data *data);
void	check_elements(t_data *data, int i, int j);
void	check_tile(t_data *data, int i, int j);
void	check_path(t_data *data);
void	flood_fill(t_data *data, char **map, int x, int y);

// shorten.c
void	*convert_xpm(t_data *data, char *path);
void	destroy_image(t_data *data, void *img);
void	put_image(t_data *data, void *img, int x, int y);

// so_long_utils.c
void	free_exit(t_data *data, char *message, int exit_code);
void	free_img(t_data *data);
void	free_more_img(t_data *data);

#endif
