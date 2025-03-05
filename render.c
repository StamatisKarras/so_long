/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:51:15 by skarras           #+#    #+#             */
/*   Updated: 2025/03/05 11:22:31 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_render(t_map *map)
{
	static t_graphics		graphics;
	t_game					game;

	game.graph = &graphics;
	game.map = map;
	game.map->moves = 0;
	if (map->width * TILE_SIZE > SCREEN_WIDTH
		|| map->height * TILE_SIZE > SCREEN_HEIGHT)
	{
		free_everything(&game);
		ft_printf("Game exceeds max screen size\n");
		exit (-1);
	}
	map->game = mlx_init(map->width * TILE_SIZE,
			map->height * TILE_SIZE, "game", false);
	if (!map->game)
	{
		free_everything(&game);
		exit(-1);
	}
	load_textures(&game);
	put_to_window(map, &graphics, map->game);
	mlx_key_hook(map->game, key_func, &game);
	mlx_loop(map->game);
	free_everything(&game);
}

void	put_to_window(t_map *map, t_graphics *graphics, mlx_t *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			graphics->y = i;
			graphics->x = j;
			load_assets(graphics, game, map->map[i][j]);
			j++;
		}
		i++;
	}
}

void	load_textures(t_game *game)
{
	game->graph->grass = create_texture("./textures/Grass_Middle.png", game);
	game->graph->path = create_texture("./textures/Path_Middle.png", game);
	game->graph->tree = create_texture("./textures/Oak_Tree.png", game);
	game->graph->collectible = create_texture("./textures/crystal.png", game);
	game->graph->exit = create_texture("./textures/House.png", game);
	game->graph->player = create_texture("./textures/player.png", game);
}

void	load_assets(t_graphics *graph, mlx_t *game, char a)
{
	if (a == '1')
	{
		mlx_image_to_window(game, graph->grass,
			graph->x * TILE_SIZE, graph->y * TILE_SIZE);
		mlx_image_to_window(game, graph->tree,
			graph->x * TILE_SIZE, graph->y * TILE_SIZE);
	}
	else
	{
		mlx_image_to_window(game, graph->path,
			graph->x * TILE_SIZE, graph->y * TILE_SIZE);
		if (a == 'E')
			mlx_image_to_window(game, graph->exit,
				graph->x * TILE_SIZE, graph->y * TILE_SIZE);
		else if (a == 'P')
			mlx_image_to_window(game, graph->player,
				graph->x * TILE_SIZE, graph->y * TILE_SIZE);
		else if (a == 'C')
			mlx_image_to_window(game, graph->collectible,
				graph->x * TILE_SIZE, graph->y * TILE_SIZE);
	}
}

mlx_image_t	*create_texture(char *path, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*dest;

	texture = mlx_load_png(path);
	if (!texture)
	{
		free_everything(game);
		exit(-1);
	}
	dest = mlx_texture_to_image(game->map->game, texture);
	mlx_delete_texture(texture);
	mlx_resize_image(dest, TILE_SIZE, TILE_SIZE);
	return (dest);
}
