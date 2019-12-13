/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:21:56 by mberglun          #+#    #+#             */
/*   Updated: 2019/12/13 16:35:47 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_piece		**pieces;

	if (argc != 2)
	{
		ft_putstr("Usage: fillit file_name\n");
		return (0);
	}
	if ((pieces = read_input(argv[1])) == NULL)
		ft_putstr("error");
	else
		ft_putstr("valid");

	while (0)
	{
	}
	return(0);
}
