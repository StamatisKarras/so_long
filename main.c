#include "so_long.h"

int	main(void)
{
	int				fd;
	static	t_map	map;

	fd = open("map.ber", O_RDONLY);
	map_shape(fd, &map);
	close(fd);
	fd = open("map.ber", O_RDONLY);
	parse_map(fd, &map);
	close(fd);
	check_walls(&map);
	check_characters(&map);
	find_player(&map);
	flood_fill(&map);
	map_render(&map);
	return(0);
}
