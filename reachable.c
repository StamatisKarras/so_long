/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reachable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:31:07 by skarras           #+#    #+#             */
/*   Updated: 2025/03/05 13:36:53 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *map)
{
	copy_arr(map);
	dfs(map, map->player_y, map->player_x);
	if (find_e_c(map))
		free_2d_copy(map, "The exit or a collectible is not reachable");
}

void	copy_arr(t_map *map)
{
	int	i;

	map->map_cp = (char **) ft_calloc(map->height + 1, sizeof(char *));
	if (!map->map_cp)
		free_and_exit_2d(map, "Faled to allocate map copy");
	i = 0;
	while (map->map[i])
	{
		map->map_cp[i] = ft_strdup(map->map[i]);
		if (!map->map_cp[i])
			free_2d_copy(map, "Faled to allocate map copy");
		i++;
	}
	map->map_cp[i] = NULL;
}

void	dfs(t_map *map, int y, int x)
{
	if (map->map_cp[y] == NULL || map->map_cp[y][x] == '1'
		|| map->map_cp[y][x] == '3')
		return ;
	if (map->map_cp[y][x] == 'E')
	{
		map->map_cp[y][x] = '1';
		return ;
	}
	map->map_cp[y][x] = '3';
	dfs(map, y + 1, x);
	dfs(map, y - 1, x);
	dfs(map, y, x + 1);
	dfs(map, y, x - 1);
}
