/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:33:24 by luinasci          #+#    #+#             */
/*   Updated: 2024/12/19 17:38:46 by luinasci         ###   ########.fr       */
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
	void	*mlx;
	void	*win;
	void	*img;
	void	*bg;
	void	*collectible;
	void	*wall;
	void	*exit;
	void	*bg_image;
	int		x;
	int		y;
	int		img_width;
	int		img_height;
	int		bg_width;
	int		bg_height;
	int		collectible_height;
	int		collectible_width;
	int		count;
	int		collectible_count;
	int		map_height;
	int		player_x;
	int		player_y;
	int		win_height;
	int		win_width;
	int		total_collectibles;
	int		collected_collectibles;
	char	**map;
	char	current_tile;
}	t_data;

int		ft_key_hook(int keycode, t_data *data);
void	ft_collectibles(t_data *data);
void	ft_load_map(t_data *data, char **map);
int		ft_validate_walls(t_data *data);
int		ft_validate_rectangle(t_data *data);
int		ft_validate_collectibles(t_data *data);
int		ft_validate_player(t_data *data);
void	ft_free_map(char **map, int height);
int		ft_map_width(char **map);
int		ft_map_height(char **map);
void	ft_initialize_window(t_data *data);
int		ft_exit(t_data *data);
void	ft_generate_background(t_data *data);
void	ft_render(t_data *data);
void	ft_background(t_data *data); //primeira versao

#endif
