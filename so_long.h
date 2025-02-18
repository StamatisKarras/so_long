/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:32:40 by skarras           #+#    #+#             */
/*   Updated: 2025/02/18 12:33:34 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Custom_Libft/libft.h"

typedef struct s_map
{
	char	**map;
	char	**map_cp;
	size_t	width;
	size_t	height;
	int		c;
}	t_map;

void	map_extention(char *map);
void	map_shape(int fd, t_map *map);
void	free_and_exit(char *to_free, char *error);
void	parse_map(int fd, t_map *map);
void	free_and_exit_2d(t_map *map, char *error);
void	copy_map(int fd, t_map *map);
void	check_walls(t_map *map);
size_t	ft_strlen_no_nl(char *str);
void	check_characters(t_map *map);
void	check_char(t_map *map);
size_t	count_char(t_map *map, char a);
void	flood_fill(t_map *map);
void	free_2d_copy(t_map *map, char *message);
void	copy_arr(t_map *map);
void	dfs(t_map *map, int x, int y);
int		find_e_c(t_map *map);
void	free_all_good(t_map *map);

#endif
