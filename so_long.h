#ifndef SO_LONG_H
# define SO_LONG_H

# include "Custom_Libft/libft.h"

typedef struct s_map
{
	char	**map;
	size_t	width;
	size_t	height;
	size_t	c;
 } t_map;

void	map_extention(char *map);
void	map_shape(int fd, t_map *map);
void	free_and_exit(char *to_free, char *error);
void	parse_map(int fd, t_map *map);
void	free_and_exit_2d(t_map *map, char * error);
void	copy_map(int fd, t_map *map);
void	check_walls(t_map *map);
size_t	ft_strlen_no_nl(char *str);
void	check_characters(t_map *map);
void	check_char(t_map *map);
size_t	count_char(t_map *map, char a);

#endif
