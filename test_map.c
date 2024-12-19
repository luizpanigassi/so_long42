#include "ft_so_long.h"

int ft_map_width(char **map)
{
	int max_width = 0;
	int row = 0;

	while (map[row] != NULL)
	{
		int width = 0;
		while(map[row][width] != '\0')
			width++;
		if (width > max_width)
			max_width = width;
		row++;
	}
	return (max_width - 1);
}

int ft_map_height(char **map)
{
	int height = 0;

	while (map[height] != NULL)
		height++;

	return (height);
}
