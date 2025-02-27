/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:32:40 by skarras           #+#    #+#             */
/*   Updated: 2025/02/27 14:12:33 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Custom_Libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_graphics
{
	mlx_image_t	*grass;
	mlx_image_t	*path;
	mlx_image_t	*tree;
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	size_t		x;
	size_t		y;
}	t_graphics;

typedef struct s_map
{
	char	**map;
	char	**map_cp;
	size_t	width;
	size_t	height;
	size_t	player_x;
	size_t	player_y;
	int		c;
	int		moves;
	mlx_t	*game;
}	t_map;

typedef struct s_game
{
	t_map		*map;
	t_graphics	*graph;
}	t_game;

# define TILE_SIZE		64
# define SCREEN_HEIGHT	2160
# define SCREEN_WIDTH	3840

void		map_extention(char *map);
void		map_shape(int fd, t_map *map);
void		free_and_exit(char *to_free, char *error);
void		parse_map(int fd, t_map *map);
void		free_and_exit_2d(t_map *map, char *error);
void		copy_map(int fd, t_map *map);
void		check_walls(t_map *map);
size_t		ft_strlen_no_nl(char *str);
void		check_characters(t_map *map);
void		check_char(t_map *map);
size_t		count_char(t_map *map, char a);
void		flood_fill(t_map *map);
void		free_2d_copy(t_map *map, char *message);
void		copy_arr(t_map *map);
void		dfs(t_map *map, int x, int y);
int			find_e_c(t_map *map);
void		put_to_window(t_map *map, t_graphics *graphics, mlx_t *game);
void		map_render(t_map *map);
void		load_textures(t_game *game);
void		load_assets(t_graphics *graph, mlx_t *game, char a);
void		find_player(t_map *map);
mlx_image_t	*create_texture(char *path, t_game *game);
void		key_func(mlx_key_data_t data, void *param);
void		move_player(t_game *game, size_t new_y, size_t new_x);
void		free_everything(t_game *game);
void		free_everything_map(t_game *game);
void		free_everything_graphics(t_game *game);

#endif
