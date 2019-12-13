/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcohen <alcohen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:47:48 by alcohen           #+#    #+#             */
/*   Updated: 2019/12/13 18:07:14 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		free_block(char **block)
{
	int	i;

	i = 0;
	while (i < 4)
		free(block[i++]);
}

/*
** Create a new piece based on the coordinates extracted with
** the dfs from validate module.
** TODO move entire piece construction to pieces.c??
*/

static int		add_piece(t_piece **pieces, int *coords)
{
	t_piece		*new;
	int			i;
	int			len;

	len = 0;
	while (len < 26 && pieces[len] != NULL)
		++len;
	if (len == 26 || !(new = (t_piece*)malloc(sizeof(t_piece))))
		return (-1);
	i = 0;
	while (i < 4)
	{
		new->coords[i][0] = coords[i] % 10;
		new->coords[i][1] = coords[i] / 10;
		++i;
	}
	new->offset[0] = 0;
	new->offset[1] = 0;
	new->id = len;
	normalize_piece(new);
	pieces[len] = new;
	return (0);
}

/*
** Extracts one block (4 rows) at a time recursively and creates a new t_piece
** struct if the block is valid.
*/

static int		check_lines(int fd, char **block, int *coords, t_piece **pieces)
{
	char	*cline;
	int		i;
	int		valid;

	cline = NULL;
	i = 0;
	while (i < 4 && get_next_line(fd, &cline) > 0 && ft_strlen(cline) == 4)
	{
		block[i++] = ft_strdup(cline);
		free(cline);
	}
	if (i != 4)
		return (-1);
	ft_memset(coords, -1, sizeof(int) * 4);
	valid = validate_tetrimino(block, coords);
	free_block(block);
	if ((valid == -1) || (add_piece(pieces, coords) == -1))
		return (-1);
	if (get_next_line(fd, &cline) > 0)
	{
		if (*cline != '\0' || check_lines(fd, block, coords, pieces) < 0)
			return (-1);
		free(cline);
	}
	return (0);
}

/*
** Top level function for validating input file.
** Handles temporarly allocated variables.
*/

t_piece			**read_input(char *file)
{
	int		fd;
	int		*coords;
	t_piece	**pieces;
	char	**block;
	int		ret;

	if ((fd = open(file, O_RDONLY)) < 0 ||
		!(block = (char**)malloc(sizeof(char*) * 4)) ||
		!(pieces = (t_piece**)malloc(sizeof(t_piece*) * 27)) ||
		!(coords = (int*)malloc(sizeof(int) * 4)))
		return (NULL);
	ft_memset(pieces, 0, sizeof(t_piece*) * 27);
	ret = check_lines(fd, block, coords, pieces);
	free(coords);
	free(block);
	if (ret == -1)
		return (NULL);
	return (pieces);
}
