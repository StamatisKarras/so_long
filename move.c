/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:25:34 by skarras           #+#    #+#             */
/*   Updated: 2025/03/05 12:51:47 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_player(t_game *game, size_t new_y, size_t new_x)
{
	if (game->map->map[new_y][new_x] == '1')
		return ;
	if (game->map->map[new_y][new_x] == 'E' && game->map->c == 0)
	{
		game->map->moves++;
		ft_printf("Move Count: %d\n", game->map->moves);
		free_everything(game);
		exit(0);
	}
	else if (game->map->map[new_y][new_x] == 'C'
		|| game->map->map[new_y][new_x] == '0')
	{
		if (game->map->map[new_y][new_x] == 'C')
			game->map->c--;
		game->map->map[game->map->player_y][game->map->player_x] = '0';
		game->map->map[new_y][new_x] = 'P';
		mlx_image_to_window(game->map->game, game->graph->path,
			game->map->player_x * TILE_SIZE, game->map->player_y * TILE_SIZE);
		mlx_image_to_window(game->map->game, game->graph->player,
			new_x * TILE_SIZE, new_y * TILE_SIZE);
		game->map->player_y = new_y;
		game->map->player_x = new_x;
		game->map->moves++;
		ft_printf("Move Count: %d\n", game->map->moves);
	}
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
		{
			free_everything(game);
			exit(0);
		}
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
