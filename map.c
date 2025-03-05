/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:32:03 by skarras           #+#    #+#             */
/*   Updated: 2025/03/05 13:36:25 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int		flag;
	size_t	size;

	flag = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (flag == 0)
		{
			if (!line)
				free_and_exit(line, "Map empty");
			map->width = ft_strlen_no_nl(line);
			map->height = 0;
			flag = 1;
		}
		if (!line)
			break ;
		size = ft_strlen_no_nl(line);
		if (map->width != size)
			free_and_exit(line, "Invalid map shape");
		map->width = size;
		map->height += 1;
		free(line);
	}
}

void	parse_map(int fd, t_map *map)
{
	size_t	i;

	map->map = (char **) ft_calloc(map->height + 1, sizeof(char *));
	if (!map->map)
	{
		ft_printf("Map allocation failure\n");
		exit(-1);
	}
	i = 0;
	while (i != map->height)
	{
		map->map[i] = (char *) ft_calloc(map->width + 1, sizeof(char));
		if (!map->map[i])
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
	while (i != map->height)
	{
		line = get_next_line(fd);
		if (!line)
			free_and_exit_2d(map, "NULL read from file");
		j = 0;
		while (j != map->width)
		{
			map->map[i][j] = line[j];
			j++;
		}
		map->map[i][j] = '\0';
		i++;
		free(line);
	}
	map->map[i] = NULL;
}
