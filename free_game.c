/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:30:06 by skarras           #+#    #+#             */
/*   Updated: 2025/02/27 12:30:04 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_everything(t_game *game)
{
	free_everything_graphics(game);
	free_everything_map(game);
}

void	free_everything_map(t_game *game)
{
	size_t	i;

	if (game->map->map)
	{
		i = 0;
		while (game->map->map[i])
			free(game->map->map[i++]);
		free(game->map->map);
	}
	if (game->map->map_cp)
	{
		i = 0;
		while (game->map->map_cp[i])
			free(game->map->map_cp[i++]);
		free(game->map->map_cp);
	}
	if (game->map->game)
		mlx_terminate(game->map->game);
}

void	free_everything_graphics(t_game *game)
{
	if (game->graph)
	{
		mlx_delete_image(game->map->game, game->graph->collectible);
		mlx_delete_image(game->map->game, game->graph->exit);
		mlx_delete_image(game->map->game, game->graph->player);
		mlx_delete_image(game->map->game, game->graph->grass);
		mlx_delete_image(game->map->game, game->graph->path);
		mlx_delete_image(game->map->game, game->graph->tree);
	}
}
