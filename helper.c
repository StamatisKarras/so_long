/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:25:03 by skarras           #+#    #+#             */
/*   Updated: 2025/02/27 11:25:05 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_no_nl(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
	{
		if (str[count] == '\n')
			break ;
		count++;
	}
	return (count);
}

int	find_e_c(t_map *map)
{
	size_t	i;

	i = 0;
	while (i != map->height)
	{
		if (ft_strchr(map->map_cp[i], 'E'))
			return (1);
		if (ft_strchr(map->map_cp[i], 'C'))
			return (1);
		i++;
	}
	return (0);
}
