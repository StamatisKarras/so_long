#include "so_long.h"
#include "stdio.h"

void	map_render(t_map *map)
{
	mlx_texture_t	*t1;
	mlx_texture_t	*t2;
	mlx_texture_t	*t3;
	mlx_texture_t	*t4;
	mlx_texture_t	*t5;
	mlx_texture_t	*t6;
	mlx_t			*game;
	static t_graphics		graphics;

	game = mlx_init(map->width * TILE_SIZE, map->height * TILE_SIZE, "game", false);
	t1 = mlx_load_png("./textures/Grass_Middle.png");
	t2 = mlx_load_png("./textures/Path_Middle.png");
	t3 = mlx_load_png("./textures/Oak_Tree.png");
	t4 = mlx_load_png("./textures/crystal.png");
	t5 = mlx_load_png("./textures/House.png");
	t6 = mlx_load_png("./textures/player.png");
	graphics.grass = mlx_texture_to_image(game, t1);
	graphics.path = mlx_texture_to_image(game, t2);
	graphics.tree = mlx_texture_to_image(game, t3);
	graphics.player = mlx_texture_to_image(game, t6);
	graphics.collectible = mlx_texture_to_image(game, t4);
	graphics.exit = mlx_texture_to_image(game, t5);
	mlx_delete_texture(t1);
	mlx_delete_texture(t2);
	mlx_delete_texture(t3);
	mlx_delete_texture(t4);
	mlx_delete_texture(t5);
	mlx_delete_texture(t6);
	mlx_resize_image(graphics.grass, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(graphics.path, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(graphics.tree, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(graphics.player, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(graphics.collectible, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(graphics.exit, TILE_SIZE, TILE_SIZE);
	put_to_window(map, &graphics, game);
	mlx_loop(game);
}

void	put_to_window(t_map *map, t_graphics *graphics, mlx_t *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while(map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			if (map->map[i][j] == '1')
			{
				mlx_image_to_window(game, graphics->grass, j * TILE_SIZE, i * TILE_SIZE);
				mlx_image_to_window(game, graphics->tree, j * TILE_SIZE, i * TILE_SIZE);
			}
			else
			{
				mlx_image_to_window(game, graphics->path, j * TILE_SIZE, i * TILE_SIZE);
				if (map->map[i][j] == '0')
					mlx_image_to_window(game, graphics->path, j * TILE_SIZE, i * TILE_SIZE);
				else if (map->map[i][j] == 'E')
					mlx_image_to_window(game, graphics->exit, j * TILE_SIZE, i * TILE_SIZE);
				else if (map->map[i][j] == 'P')
					mlx_image_to_window(game, graphics->player, j * TILE_SIZE, i * TILE_SIZE);
				else if (map->map[i][j] == 'C')
					mlx_image_to_window(game, graphics->collectible, j * TILE_SIZE, i * TILE_SIZE);
			}
			j++;
		}
		i++;
	}
}
