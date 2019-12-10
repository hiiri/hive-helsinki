/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:09:30 by mberglun          #+#    #+#             */
/*   Updated: 2019/12/10 19:14:29 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_tile(char **block, int row, int col)
{
	if (block[row][col] != '.' && block[row][col] != '#')
		return (-1);
	if (block[row][col] == '#' && !((row > 0 && block[row - 1][col] == '#') ||
		(row < 3 && block[row + 1][col] == '#') ||
		(col > 0 && block[row][col - 1] == '#') ||
		(col < 3 && block[row][col + 1] == '#')))
		return (-1);
	return (0);
}

int		parse_block(char **block)
{
	int		r;
	int		c;
	int		count;

	count = 0;
	r = 0;
	while (r < 4)
	{
		c = 0;
		while (block[r][c] != '\0')
		{
			if (check_tile(block, r, c) < 0)
				return (-1);
			if (block[r][c] == '#')
				++count;
			++c;
		}
		if (c != 4)
			return (-1);
		++r;
	}
	if (count != 4)
		return (-1);
	return (0);
}
