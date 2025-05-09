/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:27:09 by skarras           #+#    #+#             */
/*   Updated: 2025/02/27 11:54:10 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_2d_copy(t_map *map, char *message)
{
	int	i;

	i = 0;
	while (map->map_cp[i])
	{
		free(map->map_cp[i]);
		i++;
	}
	free(map->map_cp);
	free_and_exit_2d(map, message);
}

void	free_and_exit(char *to_free, char *error)
{
	free(to_free);
	ft_printf("%s\n", error);
	exit(-1);
}

void	free_and_exit_2d(t_map *map, char *error)
{
	size_t	i;

	i = 0;
	while (i != map->height)
		free(map->map[i++]);
	free(map->map);
	ft_printf("%s\n", error);
	exit(-1);
}
