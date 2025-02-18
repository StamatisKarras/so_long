/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:32:03 by skarras           #+#    #+#             */
/*   Updated: 2025/02/18 12:29:56 by skarras          ###   ########.fr       */
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

size_t	ft_strlen_no_nl(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
	{
		if (str[count] == '\n')
			break ;
		count++;
	}
	return (count);
}
