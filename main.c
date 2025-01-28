#include "so_long.h"

int	main(void)
{
	int		fd;
	t_map	map;
	int		i;

	ft_memset(&map, 0, sizeof(t_map));
	fd = open("map.ber", O_RDONLY);
	map_shape(fd, &map);
	close(fd);
	fd = open("map.ber", O_RDONLY);
	parse_map(fd, &map);
	close(fd);
	i = 0;
	while(map.map != 0)
	{
		ft_printf("%s\n", map.map[i]);
		i++;
	}
	return(0);
}
