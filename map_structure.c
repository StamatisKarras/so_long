#include "so_long.h"

void	check_walls(t_map *map)
{
	size_t	j;
	size_t	i;
	size_t	height;
	size_t	width;

	height = map->height - 1;
	width = map->width - 1;
	j = 0;
	while(j != width)
	{
		ft_printf("%c\n", map->map[height][j]);
		if (map->map[0][j] != 1 || map->map[height][j] != 1)
			free_and_exit_2d(map, "Map is not enclosed by walls");
		j++;
	}
	i = 0;
	while(i != height)
	{
		if(map->map[i][0] != 1 || map->map[i][width] != 1)
			free_and_exit_2d(map, "Map is not enclosed by walls");
		i++;
	}
	ft_printf("Wall check works");
}
