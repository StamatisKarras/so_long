/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:51:15 by skarras           #+#    #+#             */
/*   Updated: 2025/02/25 19:01:46 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_render(t_map *map)
{
	static t_graphics		graphics;
	t_game					game;

	game.graph = &graphics;
	game.map = map;
	map->game = mlx_init(map->width * TILE_SIZE,
		map->height * TILE_SIZE, "game", false);
	load_textures(&graphics, map);
	put_to_window(map, &graphics, map->game);
	mlx_key_hook(map->game, key_func, &game);
	mlx_loop(map->game);
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

void	load_textures(t_graphics *graph, t_map *map)
{
	graph->grass = create_texture("./textures/Grass_Middle.png", map);
	graph->path = create_texture("./textures/Path_Middle.png", map);
	graph->tree = create_texture("./textures/Oak_Tree.png", map);
	graph->collectible = create_texture("./textures/crystal.png", map);
	graph->exit = create_texture("./textures/House.png", map);
	graph->player = create_texture("./textures/player.png", map);
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

mlx_image_t	*create_texture(char *path, t_map *map)
{
	mlx_texture_t	*texture;
	mlx_image_t		*dest;

	texture = mlx_load_png(path);
	if (!texture)
		free_2d_copy(map, "Error loading assets");
	dest = mlx_texture_to_image(map->game, texture);
	mlx_delete_texture(texture);
	mlx_resize_image(dest, TILE_SIZE, TILE_SIZE);
	return dest;
}

void	key_func(mlx_key_data_t data, void *param)
{
	size_t	new_x;
	size_t	new_y;
	t_game	*game;

	game = (t_game *) param;
	if (data.action == MLX_PRESS)
	{
		new_x = game->map->player_x;
		new_y = game->map->player_y;
		if (data.key == MLX_KEY_ESCAPE)
			free_all_good(game->map);
		else if (data.key == MLX_KEY_W)
			new_y--;
		else if (data.key == MLX_KEY_A)
			new_x--;
		else if (data.key == MLX_KEY_S)
			new_y++;
		else if (data.key == MLX_KEY_D)
			new_x++;
		move_player(game, new_y, new_x);
	}
}
