/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:32:03 by skarras           #+#    #+#             */
/*   Updated: 2025/01/23 14:10:31 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_and_exit(char *to_free, char *error)
{
	free(to_free);
	ft_printf("%s\n", error);
	exit(-1);
}

void	map_extention(char *mapname)
{
	if (!(ft_strnstr(mapname, ".ber", ft_strlen(mapname))))
	{
		ft_printf("Map extention not .ber\n");
		exit(-1);
	}
}

void	map_shape(int fd, t_map *map)
{
	char	*line;
	size_t	size;

	line = get_next_line(fd);
	if (!line)
		free_and_exit(line, "Map empty");
	map->width = ft_strlen(line);
	map->height += 1;
	while(line)
	{
		line = get_next_line(fd);
		size = ft_strlen(line);
		if (size == 0)
			break ;
		if (map->width != size || map->width == map->height)
			free_and_exit(line, "Invalid map shape");
		map->width = size;
		map->height += 1;
		free(line);
	}
}
