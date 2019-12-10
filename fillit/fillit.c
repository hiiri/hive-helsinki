/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:17:37 by mberglun          #+#    #+#             */
/*   Updated: 2019/12/10 19:08:08 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*cline;
	char	**block;
	int		valid;

	if (argc != 2)
		return (0);

	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);

	if (!(block = (char**)malloc(sizeof(char*) * 4)))
		return (0);

	i = 1;
	while (get_next_line(fd, &cline) > 0)
	{
		if (i % 5 > 0)
		{
			block[i % 5 - 1] = ft_strdup(cline);
		}
		else
		{
			valid = parse_block(block);
			if (valid == -1 || cline[0] != '\0')
			{
				ft_putstr("Error");
				return (0);
			}
		}
		++i;
	}

	valid = parse_block(block);
	if (valid == -1)
	{
		ft_putstr("Error");
		return (0);
	}
	else
		ft_putstr("All valid");
	return (0);
}
