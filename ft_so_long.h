/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:33:24 by luinasci          #+#    #+#             */
/*   Updated: 2025/01/02 19:18:12 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define MOVE_SPEED 32

typedef struct s_data
{
	void	*bg;
	void	*bg_image;
	void	*buffer;
	void	*collectible;
	void	*exit;
	void	*img;
	void	*mlx;
	void	*win;
	void	*wall;
	int		bg_height;
	int		bg_width;
	int		collected_collectibles;
	int		collectible_count;
	int		collectible_height;
	int		collectible_width;
	int		count;
	int		img_width;
	int		img_height;
	int		map_capacity;
	int		map_height;
	int		player_x;
	int		player_y;
	int		total_collectibles;
	int		win_height;
	int		win_width;
	int		x;
	int		y;
	char	**map;
	char	current_tile;
}	t_data;

typedef struct s_point {
	int		x;
	int		y;
}	t_point;

char	**ft_create_map_copy(t_data *data);
int		ft_add_map_line(t_data *data, char *line);
int		ft_check_horizontal_walls(t_data *data, int width);
int		ft_check_reachable_items(char **map_copy, t_data *data);
int		ft_check_vertical_walls(t_data *data, int width);
int		ft_handle_exit(t_data *data);
int		ft_is_valid_position(char **map, int x, int y, int height);
int		ft_is_valid_move(int new_x, int new_y, t_data *data);
int		ft_validate_path(t_data *data);
int		ft_key_hook(int keycode, t_data *data);
int		ft_exit(t_data *data);
int		ft_validate_args(int argc, char **argv, int *fd);
int		ft_read_map(t_data *data, int fd);
int		ft_validate_map(t_data *data);
int		ft_init_mlx(t_data *data);
int		ft_load_image(void *mlx, void **img, t_data *data, char *path);
int		ft_load_assets(t_data *data);
int		ft_map_height(char **map);
int		ft_map_width(char **map);
int		ft_validate_walls(t_data *data);
int		ft_validate_rectangle(t_data *data);
int		ft_validate_collectibles(t_data *data);
int		ft_validate_player(t_data *data);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_flood_fill(char **map, int x, int y, int height);
int		ft_validate_exit(t_data *data);
void	ft_setup_game(t_data *data);
void	ft_free_map(char **map, int height);
void	ft_find_player(t_data *data, int *player_count);
void	ft_count_collectibles(t_data *data, int		*collectible_count);
void	ft_init_data(t_data *data);
void	ft_generate_background(t_data *data);
void	ft_render(t_data *data);
void	ft_initialize_window(t_data *data);
void	ft_render_tile(t_data *data, int x, int y, char tile_type);
void	ft_render_background_layer(t_data *data);
void	ft_render_game_objects(t_data *data);
void	ft_handle_collectible(t_data *data);
void	ft_get_new_position(int keycode, int *new_x, int *new_y, t_data *data);
void	ft_free_map_copy(char **map_copy, int height);
void	ft_render_tile_at_position(t_data *data, char **map_copy, int x, int y);
void	ft_update_player_tile_and_sync(t_data *data);

#endif
