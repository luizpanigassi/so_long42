/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:44:53 by luinasci          #+#    #+#             */
/*   Updated: 2025/01/06 18:21:45 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_validate_map(t_data *data)
{
	if (!ft_validate_collectibles(data) || !ft_validate_rectangle(data)
		|| !ft_validate_player(data) || !ft_validate_walls(data)
		|| !ft_validate_path(data) || !ft_validate_exit(data))
	{
		ft_free_map(data->map, data->map_height);
		return (0);
	}
	return (1);
}

int	ft_validate_args(int argc, char **argv, int *fd)
{
	if (argc != 2)
	{
		ft_printf("Come on. I need a map. You know that.\n");
		return (0);
	}
	*fd = open(argv[1], O_RDONLY);
	if (*fd < 0)
	{
		ft_printf("Come on. Get me a REAL map. Don't be a chump.\n");
		return (0);
	}
	return (1);
}

int	ft_load_assets(t_data *data)
{
	if (!ft_load_image(data->mlx, &data->bg, data, "assets/tile.xpm")
		|| !ft_load_image(data->mlx, &data->img, data, "assets/rogue.xpm")
		|| !ft_load_image(data->mlx, &data->collectible,
			data, "assets/collectible.xpm")
		|| !ft_load_image(data->mlx, &data->wall, data, "assets/wall.xpm")
		|| !ft_load_image(data->mlx, &data->exit, data, "assets/exit.xpm")
		|| !ft_load_image(data->mlx, &data->bg_image, data, "assets/tile.xpm"))
	{
		return (0);
	}
	return (1);
}

void	ft_setup_game(t_data *data)
{
	data->x = data->player_x * 32;
	data->y = data->player_y * 32;
	data->current_tile = '0';
	mlx_hook(data->win, 17, 0, ft_exit, data);
	mlx_key_hook(data->win, ft_key_hook, data);
	ft_generate_background(data);
	ft_render(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	ft_init_data(&data);
	if (!ft_validate_args(argc, argv, &fd)
		|| !ft_read_map(&data, fd)
		|| !ft_validate_map(&data)
		|| !ft_init_mlx(&data)
		|| !ft_load_assets(&data))
	{
		return (1);
	}
	ft_printf("\nYour journey begins! Get all the treasures!\n\n");
	ft_setup_game(&data);
	mlx_loop(data.mlx);
	ft_free_map(data.map, data.map_height);
	return (0);
}
