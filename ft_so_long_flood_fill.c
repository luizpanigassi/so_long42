/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_flood_fill.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:33:41 by luinasci          #+#    #+#             */
/*   Updated: 2025/01/06 18:21:11 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_flood_fill(char **map, int x, int y, int height)
{
	const int	dx[] = {1, -1, 0, 0};
	const int	dy[] = {0, 0, 1, -1};
	int			i;

	if (!ft_is_valid_position(map, x, y, height))
		return ;
	map[y][x] = 'F';
	i = 0;
	while (i < 4)
	{
		ft_flood_fill(map, x + dx[i], y + dy[i], height);
		i++;
	}
}

int	ft_is_valid_position(char **map, int x, int y, int height)
{
	return (x >= 0 && y >= 0 && y < height && map[y] != NULL
		&& x < (int)ft_strlen(map[y])
		&& map[y][x] != '1' && map[y][x] != 'F');
}

int	ft_check_reachable_items(char **map_copy, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (map_copy[i][j])
		{
			if ((data->map[i][j] == 'C' || data->map[i][j] == 'E') &&
				map_copy[i][j] != 'F')
			{
				ft_printf("Come on, dude, you gotta get to the items.\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
