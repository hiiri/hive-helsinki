/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:50:10 by mberglun          #+#    #+#             */
/*   Updated: 2019/12/11 16:55:27 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Checks that a position in the block grid is safe to follow in DFS search
*/

static int		is_safe(int row, int col, char **block, int visited[4][4])
{
	return (row >= 0 && row <= 3 && col >= 0 && col <= 3 &&
		block[row][col] == '#' && !visited[row][col]);
}

/*
** DFS search on tetrimino block grid,
** Starts with a (#) and follows a vertical or horizontal path until the end.
** Counts the number of nodes in current path
*/

static int		visit(char **block, int visited[4][4], int row, int col)
{
	int		rowdirs[4];
	int		coldirs[4];
	int		d;
	int		found;

	visited[row][col] = 1;
	rowdirs[0] = 0;
	coldirs[0] = 1;
	rowdirs[1] = 1;
	coldirs[1] = 0;
	rowdirs[2] = 0;
	coldirs[2] = -1;
	rowdirs[3] = -1;
	coldirs[3] = 0;
	found = 0;
	d = 0;
	while (d < 4)
	{
		if (is_safe(row + rowdirs[d], col + coldirs[d], block, visited))
			found += visit(block, visited, row + rowdirs[d], col + coldirs[d]);
		++d;
	}
	return (found + 1);
}

/*
** Validates that a tetrimino in a 4x4 grid is valid:
** Checks that each tile in a tetrimino is connected in sequence.
** Checks that there are ONLY 1 4 length tetrimino in the grid.
*/

int				validate_tetrimino(char **block)
{
	int		visited[4][4];
	int		pos[2];
	int		found;

	ft_memset(visited, 0, sizeof(visited));
	found = 0;
	pos[0] = -1;
	while (++pos[0] < 4)
	{
		if (ft_strlen(block[pos[0]]) != 4)
			return (-1);
		pos[1] = -1;
		while (++pos[1] < 4)
		{
			if (block[pos[0]][pos[1]] != '#' && block[pos[0]][pos[1]] != '.')
				return (-1);
			if (block[pos[0]][pos[1]] == '#' && !visited[pos[0]][pos[1]])
			{
				if (found || visit(block, visited, pos[0], pos[1]) != 4)
					return (-1);
				found = 1;
			}
		}
	}
	return (found - 1);
}
