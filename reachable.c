#include "so_long.h"

void	flood_fill(t_map *map)
{
	copy_arr(map);
	change_map(map);
}
void	copy_arr(t_map *map)
{
	int	i;

	map->map_cp = (char **) ft_calloc(map->height + 1, sizeof(char *));
	if (!map->map_cp)
		free_and_exit_2d(map, "Faled to allocate map copy");
	i = 0;
	while(map->map[i])
	{
		map->map_cp[i] = ft_strdup(map->map[i]);
		if (!map->map_cp)
			free_2d_copy(map);
		i++;
	}
	map->map_cp[i] = NULL;
}

void	change_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_cp[i])
	{
		j = 0;
		while (map->map_cp[i][j])
		{
			if (map->map_cp[i][j] == '0')
				map->map_cp[i][j] = 'S';
			else if (map->map_cp[i][j] == '1')
				map->map_cp[i][j] = 'W';
			j++;
		}
		i++;
	}
}

void	find_path()
