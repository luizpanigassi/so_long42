/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:59:36 by luinasci          #+#    #+#             */
/*   Updated: 2025/01/02 18:52:07 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

char	**ft_create_map_copy(t_data *data)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (data->map_height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < data->map_height)
	{
		copy[i] = ft_strdup(data->map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	ft_free_map_copy(char **map_copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

int	ft_check_vertical_walls(t_data *data, int width)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		if (data->map[i][0] != '1' || data->map[i][width - 2] != '1')
		{
			ft_printf("Your map is leaking! Get some walls around it!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_horizontal_walls(t_data *data, int width)
{
	int	i;

	i = 0;
	while (i < width - 1)
	{
		if (data->map[0][i] != '1' || data->map[data->map_height - 1][i] != '1')
		{
			ft_printf("Your map is leaking! Get some walls around it!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_count_collectibles(t_data *data, int *collectible_count)
{
	int	x;
	int	y;

	*collectible_count = 0;
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
				(*collectible_count)++;
			x++;
		}
		y++;
	}
}
