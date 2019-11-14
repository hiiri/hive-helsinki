/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcohen <alcohen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:45:40 by alcohen           #+#    #+#             */
/*   Updated: 2019/11/14 13:30:48 by alcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char *line;
	if (argc != 2)
		return (-1);
	int fd = open(argv[1], O_RDONLY);

	//printf("%d", fd);
	if (fd < 0)
		return (-1);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
	}
}
