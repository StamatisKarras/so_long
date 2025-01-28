#include "so_long.h"

void	free_and_exit_2d(t_map *map, char *error)
{
	size_t	i;

	i = 0;
	while(i != map->height)
		free(map->map[i++]);
	free(map->map);
	ft_printf("%s\n", error);
	exit(-1);
}

void	parse_map(int fd, t_map *map)
{
	size_t	i;

	i = 0;
	map->map = (char **)  ft_calloc(map->height + 1, sizeof(char *));
	if (!map->map)
		free_and_exit_2d(map, "Allocation failure");
	while(i != map->height)
	{
		map->map[i] = (char *) ft_calloc(map->width + 1, sizeof(char));
		if(!map->map[i])
			free_and_exit_2d(map, "Allocation failure");
		i++;
	}
	copy_map(fd, map);
}

void	copy_map(int fd, t_map *map)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	while(i != map->height)
	{
		line = get_next_line(fd);
		if (!line)
			free_and_exit_2d(map, "NULL read from file");
		j = 0;
		while(j != map->width)
		{
			map->map[i][j] = line[j];
			j++;
		}
		map->map[i][j] = '\0';
		i++;
		free(line);
	}
}
