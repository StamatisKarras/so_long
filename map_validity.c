/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:32:03 by skarras           #+#    #+#             */
/*   Updated: 2025/02/05 11:56:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_and_exit(char *to_free, char *error)
{
	free(to_free);
	ft_printf("%s\n", error);
	exit(-1);
}

void	map_extention(char *mapname)
{
	if (!(ft_strnstr(mapname, ".ber", ft_strlen(mapname))))
	{
		ft_printf("Map extention not .ber\n");
		exit(-1);
	}
}

void	map_shape(int fd, t_map *map)
{
	char	*line;
	int		flag;
	size_t	size;

	flag = 0;
	while(1)
	{
		line = get_next_line(fd);
		if (flag == 0)
		{
			if (!line)
				free_and_exit(line, "Map empty");
			map->width = ft_strlen_no_nl_arr(line);
			map->height = 0;
			flag = 1;
		}
		if (!line)
			break ;
		size = ft_strlen_no_nl_arr(line);
		if (map->width != size || map->width == map->height)
			free_and_exit(line, "Invalid map shape");
		map->width = size;
		map->height += 1;
		free(line);
	}
}
size_t	ft_strlen_no_nl_arr(char *str)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			continue ;
		}
		i++;
		count++;
	}
	return (count);
}
