/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_handlers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:09:38 by luinasci          #+#    #+#             */
/*   Updated: 2025/01/06 18:19:55 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_exit(t_data *data)
{
	void	*images[8];
	int		i;

	images[0] = data->buffer;
	images[1] = data->bg;
	images[2] = data->img;
	images[3] = data->collectible;
	images[4] = data->wall;
	images[5] = data->exit;
	images[6] = data->bg_image;
	images[7] = NULL;
	i = 0;
	while (images[i])
	{
		if (images[i])
			mlx_destroy_image(data->mlx, images[i]);
		i++;
	}
	mlx_destroy_window(data->mlx, data->win);
	ft_free_map(data->map, data->map_height);
	exit(0);
	return (0);
}

void	ft_handle_collectible(t_data *data)
{
	data->collected_collectibles++;
	data->map[data->y / 32][data->x / 32] = '0';
	if (data->collected_collectibles < data->total_collectibles)
		ft_printf("\nYou've found a treasure! Only %d to go!\n\n",
			data->total_collectibles - data->collected_collectibles);
	else
		ft_printf("\nYay! You've got them all! Now GTFO, petty thief.\n\n");
}

int	ft_handle_exit(t_data *data)
{
	ft_printf("\nYAY! You made it, you can press keys!\n\n");
	ft_exit(data);
	return (1);
}
