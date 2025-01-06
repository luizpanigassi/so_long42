/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_validators.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:52:50 by luinasci          #+#    #+#             */
/*   Updated: 2025/01/06 18:51:05 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_validate_walls(t_data *data)
{
	int	width;

	width = ft_strlen(data->map[0]);
	return (ft_check_vertical_walls(data, width)
		&& ft_check_horizontal_walls(data, width));
}

int	ft_validate_rectangle(t_data *data)
{
	int	width;
	int	i;

	i = 1;
	width = ft_strlen(data->map[0]);
	if (width == data->map_height)
	{
		ft_printf("A SQUARE? We do not tolerate squares here.\n");
		return (0);
	}
	while (i < data->map_height)
	{
		if (ft_strlen(data->map[i]) != width)
		{
			ft_printf("That's one weird map you've got there, friend.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_validate_collectibles(t_data *data)
{
	int	collectible_count;

	ft_count_collectibles(data, &collectible_count);
	if (collectible_count == 0)
	{
		ft_printf("Wait? No treasure? Seriously?\n");
		return (0);
	}
	data->total_collectibles = collectible_count;
	data->collected_collectibles = 0;
	return (1);
}

int	ft_validate_player(t_data *data)
{
	int	player_count;

	ft_find_player(data, &player_count);
	if (player_count != 1)
	{
		ft_printf("Seriously. ONE player. I need ONE player. That's it.\n");
		return (0);
	}
	return (1);
}

int	ft_validate_path(t_data *data)
{
	char	**map_copy;
	int		valid;

	map_copy = ft_create_map_copy(data);
	if (!map_copy)
	{
		ft_printf("Failed to allocate memory for map copy.\n");
		return (0);
	}
	ft_flood_fill(map_copy, data->player_x, data->player_y, data->map_height);
	valid = ft_check_reachable_items(map_copy, data);
	ft_free_map_copy(map_copy, data->map_height);
	return (valid);
}
