/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_validators2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:35:20 by luinasci          #+#    #+#             */
/*   Updated: 2025/01/07 17:08:49 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_validate_exit(t_data *data)
{
	int	exit_count;
	int	i;
	int	j;

	exit_count = 0;
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < ft_strlen(data->map[i]))
		{
			if (data->map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (exit_count != 1)
	{
		ft_printf("One exit is all I need, friend.\n");
		return (0);
	}
	return (1);
}

int	ft_validate_map_characters(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] != 'E' && map[y][x] != 'P' &&
				map[y][x] != 'C' && map[y][x] != '1' &&
				map[y][x] != '0' && map[y][x] != '\n')
			{
				ft_printf("Your map is crazy, fix it.\n", map[y][x]);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
