/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcohen <alcohen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:47:48 by alcohen           #+#    #+#             */
/*   Updated: 2019/12/11 20:05:50 by alcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_lines(int fd, char **block)
{
	char	*cline;
	int		i;
	int		valid;

	cline = NULL;
	i = 0;
	while (i < 4 && get_next_line(fd, &cline) > 0 && ft_strlen(cline) == 4)
	{
		block[i] = ft_strdup(cline);
		i++;
	}
	if (i != 4)
		return (-1);
	valid = validate_tetrimino(block);
	if (valid == -1)
		return (-1);
	if (get_next_line(fd, &cline) > 0)
	{
		if (*cline != '\0' || check_lines(fd, &cline) < 0)
			return (-1);
	}
	return (0);
}

static int		check_input(int fd, char **block)
{
	if (check_lines(fd, block) < 0)
		return (-1);
	return (1);
}

int				read_input(char *file)
{
	int		fd;
	char	**block;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	if (!(block = (char**)malloc(sizeof(char*) * 4)))
		return (-1);
	if (check_input(fd, block) == -1)
		return (-1);
	return (0);
}
