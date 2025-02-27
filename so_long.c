/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:27:20 by skarras           #+#    #+#             */
/*   Updated: 2025/02/27 13:59:51 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int				fd;
	static t_map	map;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("ERROR");
			exit(-1);
		}
		map_shape(fd, &map);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		parse_map(fd, &map);
		close(fd);
		check_walls(&map);
		check_characters(&map);
		find_player(&map);
		flood_fill(&map);
		map_render(&map);
	}
	return (0);
}
