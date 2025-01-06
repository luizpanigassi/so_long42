/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:03:46 by luinasci          #+#    #+#             */
/*   Updated: 2025/01/02 18:47:31 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_render_game_objects(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < ft_strlen(data->map[y]))
		{
			if (data->map[y][x] != '0')
				ft_render_tile(data, x, y, data->map[y][x]);
			x++;
		}
		y++;
	}
}

void	ft_render_background_layer(t_data *data)
{
	int	x;
	int	y;

	if (!data->map)
	{
		ft_printf("No map!");
		return ;
	}
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < ft_strlen(data->map[y]))
		{
			mlx_put_image_to_window(data->mlx,
				data->win, data->bg, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	ft_render_tile(t_data *data, int x, int y, char tile_type)
{
	int	px;
	int	py;

	px = x * 32;
	py = y * 32;
	mlx_put_image_to_window(data->mlx, data->win, data->bg, px, py);
	if (tile_type == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, px, py);
	else if (tile_type == 'C')
		mlx_put_image_to_window(data->mlx,
			data->win, data->collectible, px, py);
	else if (tile_type == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit, px, py);
}

void	ft_render_tile_at_position(t_data *data, char **map_copy, int x, int y)
{
	if (map_copy[y][x] == 'F')
		ft_render_tile(data, x, y, data->map[y][x]);
	else if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx,
			data->win, data->wall, x * 32, y * 32);
}

void	ft_render(t_data *data)
{
	char	**map_copy;
	int		x;
	int		y;

	map_copy = ft_create_map_copy(data);
	ft_flood_fill(map_copy, data->player_x, data->player_y, data->map_height);
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < ft_strlen(data->map[y]))
		{
			ft_render_tile_at_position(data, map_copy, x, y);
			x++;
		}
		y++;
	}
	ft_update_player_tile_and_sync(data);
	ft_free_map(map_copy, data->map_height);
}
