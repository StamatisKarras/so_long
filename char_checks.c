/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:28:13 by skarras           #+#    #+#             */
/*   Updated: 2025/02/27 12:50:19 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map[0][i])
	{
		if (map->map[0][i] != '1' ||
			map->map[map->height - 1][i] != '1')
			free_and_exit_2d(map, "Map not enclosed by walls");
		i++;
	}
	i = 0;
	while (map->map[i])
	{
		if (map->map[i][0] != '1' ||
			map->map[i][map->width - 1] != '1')
			free_and_exit_2d(map, "Map not enclosed by walls");
		i++;
	}
}

void	check_characters(t_map *map)
{
	size_t	i;
	size_t	j;
	char	*search;

	j = 0;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			search = ft_strchr("01CEP", map->map[i][j]);
			if (!search)
				free_and_exit_2d(map, "Invalid Characters in Map");
			j++;
		}
		i++;
	}
	check_char(map);
}

void	check_char(t_map *map)
{
	int	e;
	int	p;

	e = 0;
	p = 0;
	e = count_char(map, 'E');
	p = count_char(map, 'P');
	map->c = count_char(map, 'C');
	if (e != 1)
		free_and_exit_2d(map, "Invalid EXIT");
	if (p != 1)
		free_and_exit_2d(map, "Invalid Player");
	if (map->c < 1)
		free_and_exit_2d(map, "Not enough collectibles");
}

size_t	count_char(t_map *map, char a)
{
	int		i;
	int		j;
	size_t	count;

	i = 0;
	count = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == a)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
