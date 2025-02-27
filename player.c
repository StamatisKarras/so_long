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
		free_all_good(game->map);
	else if (game->map->map[new_y][new_x] == 'C'
		|| game->map->map[new_y][new_x] == '0')
	{
		if (game->map->map[new_y][new_x] == 'C')
			game->map->c--;
		game->map->map[game->map->player_y][game->map->player_x] = '0';
		game->map->map[new_y][new_x] = 'P';
		mlx_image_to_window(game->map->game, game->graph->path, game->map->player_x *TILE_SIZE, game->map->player_y * TILE_SIZE);
		mlx_image_to_window(game->map->game, game->graph->player, new_x * TILE_SIZE, new_y * TILE_SIZE);
		game->map->player_y = new_y;
		game->map->player_x = new_x;
	}
}
