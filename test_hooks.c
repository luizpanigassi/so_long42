#include "ft_so_long.h"

int ft_key_hook(int keycode, t_data *data)
{
	mlx_clear_window(data->mlx, data->win);

	if (keycode == 65307) // ESC
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	int new_x = data->x;
	int new_y = data->y;
	if (keycode == 115 || keycode == 65364) // S/Down
		new_y += MOVE_SPEED;
	if (keycode == 97 || keycode == 65361) // A/Left
		new_x -= MOVE_SPEED;
	if (keycode == 119 || keycode == 65362) // W/Up
		new_y -= MOVE_SPEED;
	if (keycode == 100 || keycode == 65363) // D/Right
		new_x += MOVE_SPEED;

	char next_tile = data->map[new_y / 32][new_x / 32];
	if (next_tile != '1')
	{
		if (next_tile == 'C')
		{
			data->collected_collectibles++;
			if (data->collected_collectibles < data->total_collectibles)
				ft_printf("A treasure! Only %d to go!\n", data->total_collectibles - data->collected_collectibles);
			else
				ft_printf("Yay! You've got them all! Now GTFO, petty thief,\n");
		}
		if (data->current_tile == 'C')
			data->map[data->y / 32][data->x / 32] = '0';

		data->x = new_x;
		data->y = new_y;
		data->current_tile = next_tile;
	}
	if (data->map[data->y / 32][data->x / 32] == 'E')
	{
		if (data->collected_collectibles == data->total_collectibles)
		{
			ft_printf("YAY! You made it, you can press keys!\n");
			mlx_destroy_window(data->mlx, data->win);
			exit(0);
		}
		else
		{
			ft_printf("Come on, don't be lazy. Get everything, Snorlax.\n");
			ft_printf("You still have %d left.\n", data->total_collectibles - data->collected_collectibles);
		}
	}
	data->count++;
	ft_printf("Pressed %d times\n", data->count);
	ft_background(data);
	return (0);
}

void ft_background(t_data *data)
{
	int y = 0;
	int x;

	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->bg, x, y);
			if ((y / 32) < data->map_height && (x / 32) < ft_strlen(data->map[y / 32]))
			{
				char tile = data->map[y / 32][x / 32];
				if (tile == '1')
					mlx_put_image_to_window(data->mlx, data->win, data->wall, x, y);
				else if (tile == 'E')
					mlx_put_image_to_window(data->mlx, data->win, data->exit, x, y);
				else if (tile == 'C')
					mlx_put_image_to_window(data->mlx, data->win, data->collectible, x, y);
			}
			x += 32;
		}
		y += 32;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
}

void ft_free_map(char **map, int height)
{
	int i = 0;

	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void ft_initialize_window(t_data *data)
{
	int map_width = ft_map_width(data->map);
	int map_height = ft_map_height(data->map);

	data->win_width = map_width * 32;
	data->win_height = map_height * 32;

	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height, "This is a test!");
}

int ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_free_map(data->map, data->map_height);
	exit (0);
	return (0);
}
