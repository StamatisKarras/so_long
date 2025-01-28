#include "so_long.h"

int	main(void)
{
	int		fd;
	t_map	map;

	ft_memset(&map, 0, sizeof(t_map));
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	map_shape(fd, &map);
	close(fd);
	fd = open("map.ber", O_RDONLY);
	parse_map(fd, &map);
	close(fd);
	return(0);
}
