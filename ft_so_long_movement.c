/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_movement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:08:38 by luinasci          #+#    #+#             */
/*   Updated: 2025/01/06 18:23:14 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_key_hook(int keycode, t_data *data)
{
	int		new_x;
	int		new_y;
	char	next_tile;

	if (keycode == 65307)
		ft_exit(data);
	ft_get_new_position(keycode, &new_x, &new_y, data);
	if (!ft_is_valid_move(new_x, new_y, data))
		return (0);
	next_tile = data->map[new_y / 32][new_x / 32];
	if (next_tile == 'C')
		ft_handle_collectible(data);
	else if (next_tile == 'E')
	{
		if (!ft_handle_exit(data))
			return (0);
	}
	data->x = new_x;
	data->y = new_y;
	data->count++;
	ft_printf("You've taken %d steps\n", data->count);
	ft_render(data);
	return (0);
}

void	ft_get_new_position(int keycode, int *new_x, int *new_y, t_data *data)
{
	*new_x = data->x;
	*new_y = data->y;
	if (keycode == 115 || keycode == 65364)
		*new_y += MOVE_SPEED;
	else if (keycode == 97 || keycode == 65361)
		*new_x -= MOVE_SPEED;
	else if (keycode == 119 || keycode == 65362)
		*new_y -= MOVE_SPEED;
	else if (keycode == 100 || keycode == 65363)
		*new_x += MOVE_SPEED;
}

int	ft_is_valid_move(int new_x, int new_y, t_data *data)
{
	char	next_tile;

	if (new_y / 32 < 0 || new_y / 32 >= data->map_height
		|| new_x / 32 < 0 || new_x / 32 >= ft_strlen(data->map[new_y / 32]))
		return (0);
	next_tile = data->map[new_y / 32][new_x / 32];
	if (next_tile == '1')
		return (0);
	if (next_tile == 'E' && data->collected_collectibles
		!= data->total_collectibles)
	{
		ft_printf("\nCome on, don't be lazy. Get everything, Snorlax.\n");
		ft_printf("You still have %d left.\n\n",
			data->total_collectibles - data->collected_collectibles);
		return (0);
	}
	return (1);
}
