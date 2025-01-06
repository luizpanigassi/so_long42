/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:49:53 by luinasci          #+#    #+#             */
/*   Updated: 2025/01/02 19:05:25 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_map_width(char **map)
{
	int	max_width;
	int	row;
	int	width;

	max_width = 0;
	row = 0;
	while (map[row] != NULL)
	{
		width = 0;
		while (map[row][width] != '\0')
			width++;
		if (width > max_width)
			max_width = width;
		row++;
	}
	return (max_width - 1);
}

int	ft_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height] != NULL)
		height++;
	return (height);
}

int	ft_add_map_line(t_data *data, char *line)
{
	if (data->map_height < 101)
	{
		data->map[data->map_height] = ft_strdup(line);
		data->map_height++;
	}
	else
	{
		ft_printf("Your map is HUGE!\n");
		free(line);
		return (0);
	}
	return (1);
}

int	ft_read_map(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	data->map = malloc(sizeof(char *) * 101);
	if (!data->map)
	{
		ft_printf("I've screwed up allocating memory for the map, sorry.\n");
		return (0);
	}
	data->map_height = 0;
	while (line != NULL)
	{
		if (!ft_add_map_line(data, line))
			break ;
		free(line);
		line = get_next_line(fd);
	}
	data->map[data->map_height] = NULL;
	close(fd);
	return (1);
}
