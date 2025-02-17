#include "so_long.h"

void	check_walls(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map[0][i])
	{
		if (map->map[0][i] != '1' ||
			 map->map[map->height - 1][i] != '1')
			free_and_exit_2d(map, "Map not enclocude by walls");
		i++;
	}
	i = 0;
	while (map->map[i])
	{
		if (map->map[i][0] != '1' ||
			 map->map[i][map->width - 1] != '1')
			free_and_exit_2d(map, "Map not enclocude by walls");
		i++;
	}
}

void	check_characters(t_map *map)
{
	size_t	i;
	size_t	j;
	char	*search;

	j = 0;
	i = 0;
	while(map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			search = ft_strchr("01CEP", map->map[i][j]);
			if(!search)
				free_and_exit_2d(map, "Invalid Characters in Map");
			j++;
		}
		i++;
	}
}

/* void	character_num(t_map *map)
{
	int	i;
	int	c;
	int	e;
	int	p;

	i = 0;
	c = 0;
	e = 0;
	p = 0;
	while(map->map[i])
	{

	}
} */
