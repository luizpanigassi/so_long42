/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:38:39 by luinasci          #+#    #+#             */
/*   Updated: 2025/01/02 18:48:16 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_find_player(t_data *data, int *player_count)
{
	int	x;
	int	y;

	*player_count = 0;
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				(*player_count)++;
				data->player_x = x;
				data->player_y = y;
			}
			x++;
		}
		y++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_init_data(t_data *data)
{
	data->bg = NULL;
	data->img = NULL;
	data->collectible = NULL;
	data->wall = NULL;
	data->exit = NULL;
	data->bg_image = NULL;
	data->win = NULL;
	data->count = 0;
	data->map_height = 0;
}

void	ft_update_player_tile_and_sync(t_data *data)
{
	int	player_tile_x;
	int	player_tile_y;

	mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
	player_tile_x = data->x / 32;
	player_tile_y = data->y / 32;
	if (data->map[player_tile_y][player_tile_x] == 'C')
		data->map[player_tile_y][player_tile_x] = '0';
	mlx_do_sync(data->mlx);
}
