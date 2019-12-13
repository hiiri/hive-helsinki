/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcohen <alcohen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:45:05 by alcohen           #+#    #+#             */
/*   Updated: 2019/12/13 20:25:47 by alcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** get amount of blocks to determine min map size
** if solver fails, get a bigger map, free last map and try solving again
*/

// maybe add a check to map.c make_map() if map is not null, free it (so if new map is requested)
// this would avoid manager having to call free map

static int	calc_map_size(t_piece **pieces)
{
	int i;
	int	size;

	i = 0;
	while (pieces[i])
		i++;
	size = ft_sqrt(pieces[i - 1]->id * 4);
	return (size-1);
}

void	print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putstr("\n");
		++i;
	}
	ft_putstr("\n");
}

int		manager(char *input)
{
	t_piece		**pieces;
	char 		**map;
	int			map_size;

	if ((pieces = read_input(input)) == NULL)
		return (-1);
	map_size = calc_map_size(pieces);

	map = make_map(map_size);
	while (!(solver(map, pieces, map_size, 0)))
	{
		map_size++;
		map = make_map(map_size);
	}
	int i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
