#include "ft_so_long.h"

int main(int argc, char **argv)
{
	t_data data;
	int fd;
	char *line;

	data.count = 0;
	if (argc != 2)
	{
		printf("Come on. I need a map. You know that.\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Come on. Get me a REAL map. Don't be a chump.\n");
		return (1);
	}
	data.map_height = 0;
	data.map = malloc(sizeof(char *	) * 101);
	if (!data.map)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		data.map[data.map_height] = ft_strdup(line);
		data.map_height++;
		free(line);
	}
	data.map[data.map_height] = NULL;
	close(fd);
	if (!ft_validate_collectibles(&data) || !ft_validate_rectangle(&data) || !ft_validate_player(&data) || !ft_validate_walls(&data))
	{
		ft_free_map(data.map, data.map_height);
		return(1);
	}
	data.x = data.player_x * 32;
	data.y = data.player_y * 32;
	data.current_tile = '0';
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		ft_printf("WTH, mlx failed\n");
		return (1);
	}
	ft_initialize_window(&data);
	data.bg = mlx_xpm_file_to_image(data.mlx, "assets/tile.xpm", &data.bg_width, &data.bg_height);
	if (!data.bg || data.bg_height != 32 || data.bg_width != 32)
	{
		ft_printf("Get some better background, bub\n");
		ft_free_map(data.map, data.map_height);
		mlx_destroy_window(data.mlx, data.win);
		return (1);
	}
	data.img = mlx_xpm_file_to_image(data.mlx, "assets/rogue.xpm", &data.img_width, &data.img_height);
	if (!data.img)
	{
		ft_printf("Get some better knights, bub\n");
		ft_free_map(data.map, data.map_height);
		mlx_destroy_window(data.mlx, data.win);
		return (1);
	}
	data.collectible = mlx_xpm_file_to_image(data.mlx, "assets/collectible.xpm", &data.img_width, &data.img_height);
	if (!data.collectible)
	{
		ft_printf("Get some better collectibles, bub\n");
		ft_free_map(data.map, data.map_height);
		mlx_destroy_window(data.mlx, data.win);
		return (1);
	}
	data.wall = mlx_xpm_file_to_image(data.mlx, "assets/wall.xpm", &data.img_width, &data.img_height);
	if (!data.wall)
	{
		ft_printf("Get some better walls, bub\n");
		ft_free_map(data.map, data.map_height);
		mlx_destroy_window(data.mlx, data.win);
		return (1);
	}
	data.exit = mlx_xpm_file_to_image(data.mlx, "assets/exit.xpm", &data.img_width, &data.img_height);
	if( !data.exit)
	{
		ft_printf("Get some better walls, bub\n");
		ft_free_map(data.map, data.map_height);
		mlx_destroy_window(data.mlx, data.win);
		return (1);
	}
	ft_background(&data);
	mlx_key_hook(data.win, ft_key_hook, &data);
	mlx_loop(data.mlx);
	ft_free_map(data.map, data.map_height);
	return (0);
}
