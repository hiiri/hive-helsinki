/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:50:10 by mberglun          #+#    #+#             */
/*   Updated: 2019/12/13 16:35:10 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Checks that a position in the block grid is safe to follow in DFS search
*/

static int	is_safe(int row, int col, char **block, int visited[4][4])
{
	return (row >= 0 && row <= 3 && col >= 0 && col <= 3 &&
		block[row][col] == '#' && !visited[row][col]);
}

/*
** Returns a new x or y coordinate based on ix value (0 to 3).
** Used in the grid based dfs which moves vertically and horizontally
*/

static int	get_dir(int ix, int dir)
{
	int		rowdirs[4];
	int		coldirs[4];

	rowdirs[0] = 0;
	coldirs[0] = 1;
	rowdirs[1] = 1;
	coldirs[1] = 0;
	rowdirs[2] = 0;
	coldirs[2] = -1;
	rowdirs[3] = -1;
	coldirs[3] = 0;
	if (dir)
		return (coldirs[ix]);
	return (rowdirs[ix]);
}

/*
** DFS search on tetrimino block grid,
** Starts with a (#) and follows a vertical or horizontal path until the end.
** Counts the number of nodes in current path
*/

static int	visit(char **block, int visited[4][4], int *pos, int *coords)
{
	int		ix;
	int		j;
	int		found;
	int		newpos[2];

	visited[pos[0]][pos[1]] = 1;
	found = 0;
	ix = 0;
	while (ix < 4)
	{
		newpos[0] = pos[0] + get_dir(ix, 0);
		newpos[1] = pos[1] + get_dir(ix, 1);
		if (is_safe(newpos[0], newpos[1], block, visited))
			found += visit(block, visited, newpos, coords);
		++ix;
	}
	if (found < 5)
	{
		j = 0;
		while (coords[j] > 0 && j < 4)
			j++;
		if (j < 4)
			coords[j] = pos[0] * 10 + pos[1];
	}
	return (found + 1);
}

/*
** Validates that a tetrimino in a 4x4 grid is valid:
** Checks that each tile in a tetrimino is connected in sequence.
** Checks that there are ONLY 1 4 length tetrimino in the grid.
*/

int			validate_tetrimino(char **block, int *coords)
{
	int		visited[4][4];
	int		pos[2];
	int		found;

	ft_memset(visited, 0, sizeof(visited));
	found = 0;
	pos[0] = -1;
	while (++pos[0] < 4)
	{
		pos[1] = -1;
		while (++pos[1] < 4)
		{
			if (block[pos[0]][pos[1]] != '#' && block[pos[0]][pos[1]] != '.')
				return (-1);
			if (block[pos[0]][pos[1]] == '#' && !visited[pos[0]][pos[1]])
			{
				if (found || visit(block, visited, pos, coords) != 4)
					return (-1);
				found = 1;
			}
		}
	}
	return (found - 1);
}
