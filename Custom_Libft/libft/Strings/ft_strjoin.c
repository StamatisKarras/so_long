/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarras <skarras@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:09:49 by codespace         #+#    #+#             */
/*   Updated: 2025/01/20 13:25:22 by skarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	total;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2);
	nstr = (char *) malloc(total + 1);
	if (!nstr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		nstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		nstr[i++] = s2[j++];
	nstr[i] = '\0';
	return (nstr);
}
