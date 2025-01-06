/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:05:20 by luinasci          #+#    #+#             */
/*   Updated: 2025/01/02 19:17:13 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_initialize_window(t_data *data)
{
	data->win_width = ft_map_width(data->map) * 32;
	data->win_height = ft_map_height(data->map) * 32;
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"Quest for the treasure!");
	data->buffer = mlx_new_image(data->mlx, data->win_width, data->win_height);
}

void	ft_generate_background(t_data *data)
{
	ft_render_background_layer(data);
	ft_render_game_objects(data);
}

int	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf("WTH, mlx failed? How could you screw it up?\n");
		return (0);
	}
	ft_initialize_window(data);
	return (1);
}

int	ft_load_image(void *mlx, void **img, t_data *data, char *path)
{
	int		width;
	int		height;
	char	*error_msg;

	if (ft_strcmp(path, "assets/tile.xpm") == 0)
		error_msg = "Get some better background, bub";
	else if (ft_strcmp(path, "assets/rogue.xpm") == 0)
		error_msg = "Get some better knights, bub";
	else if (ft_strcmp(path, "assets/collectible.xpm") == 0)
		error_msg = "Get some better collectibles, bub";
	else if (ft_strcmp(path, "assets/wall.xpm") == 0)
		error_msg = "Get some better walls, bub";
	else if (ft_strcmp(path, "assets/exit.xpm") == 0)
		error_msg = "Get some better exits, bub";
	*img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!*img || (ft_strcmp(path, "assets/tile.xpm")
			== 0 && (height != 32 || width != 32)))
	{
		ft_printf("%s\n", error_msg);
		ft_free_map(data->map, data->map_height);
		mlx_destroy_window(data->mlx, data->win);
		return (0);
	}
	return (1);
}
