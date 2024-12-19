#include "ft_so_long.h"

int ft_validate_walls(t_data *data)
{
	int width = ft_strlen(data->map[0]);
	int i = 0;

	while (i < data->map_height)
	{
		if (data->map[i][0] != '1' || data->map[i][width - 2] != '1')
		{
			ft_printf("Your map is leaking! Get some walls around it!\n");
			return (0);
		}
		i++;
	}

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

int ft_validate_rectangle(t_data *data)
{
	int width = ft_strlen(data->map[0]);
	int i = 1;

	while (i < data->map_height)
	{
		if (ft_strlen(data->map[i]) != width)
		{
			ft_printf("A SQUARE? We do not appreciate squares here.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int ft_validate_collectibles(t_data *data)
{
	int collectible_count = 0;
	int x;
	int y = 0;

	while (y < data->map_height)
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
				collectible_count++;
			x++;
		}
		y++;
	}
	if (collectible_count == 0)
	{
		ft_printf("Wait? No treasure? Seriously?\n");
		return (0);
	}
	data->total_collectibles = collectible_count;
	data->collected_collectibles = 0;
	return (1);
}

int ft_validate_player(t_data *data)
{
	int x;
	int y = 0;
	int player_count = 0;

	while (y < data->map_height)
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				player_count++;
				data->player_x = x;
				data->player_y = y;
			}
			x++;
		}
		y++;
	}
	if (player_count != 1)
	{
		printf("Seriously. ONE player. I need ONE player. That's it.\n");
		return (0);
	}
	return (1);
}
