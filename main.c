#include "so_long.h"

int	main(void)
{
	int		fd;
	t_map	map;

	ft_memset(&map, 0, sizeof(t_map));
	fd = open("map.ber", O_RDONLY);
	map_shape(fd, &map);
	close(fd);
	ft_printf("Height: %d\nWidth: %d\n", map.height, map.width);
	fd = open("map.ber", O_RDONLY);
	parse_map(fd, &map);
	close(fd);
	check_walls(&map);
	return(0);
}
