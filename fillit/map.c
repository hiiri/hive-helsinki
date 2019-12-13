/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcohen <alcohen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:28:29 by alcohen           #+#    #+#             */
/*   Updated: 2019/12/13 18:25:13 by alcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**make_map(int size)
{
	int		i;
	int		j;
	char	**map;

	if (!(map = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		map[i] = ft_strnew((size_t)size);
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	block_to_map(char **map, t_piece *piece)
{
	int	i;
	int x;
	int y;

	i = 0;
	while (i < 4)
	{
		x = piece->coords[i][0] + piece->offset[0];
		y = piece->coords[i][1] + piece->offset[1];
		map[y][x] = piece->id + 65;
		i++;
	}
}
