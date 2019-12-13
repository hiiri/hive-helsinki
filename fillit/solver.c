/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:24:51 by mberglun          #+#    #+#             */
/*   Updated: 2019/12/13 20:29:39 by alcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_valid(char **map, t_piece *piece, int x, int y)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (map[piece->coords[i][1] + y][piece->coords[i][0] + x] != '.')
			return (0);
		++i;
	}
	return (1);
}

static void		remove_piece_from_map(char **map, char id)
{
	int		x;
	int		y;
	int		count;

	x = 0;
	count = 0;
	while (map[x] != NULL)
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (map[x][y] == (char)(id + 65))
			{
				map[x][y] = '.';
				if (++count >= 4)
					return ;
			}
			++y;
		}
		++x;
	}
}

int				solver(char **map, t_piece **pieces, int size, int ix)
{
	int		x;
	int		y;

	if (pieces[ix] == NULL)
		return (1);
	y = 0;
	while ((y + pieces[ix]->height) <= size)
	{
		x = 0;
		while ((x + pieces[ix]->width) <= size)
		{
			if (check_valid(map, pieces[ix], x, y))
			{
				pieces[ix]->offset[0] = x;
				pieces[ix]->offset[1] = y;
				block_to_map(map, pieces[ix]);
				system("clear");
				print_map(map);
				if (solver(map, pieces, size, ix + 1))
					return (1);
				else
					remove_piece_from_map(map, pieces[ix]->id);
			}
			++x;
		}
		++y;
	}
	return (0);
}
