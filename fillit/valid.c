/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:17:37 by mberglun          #+#    #+#             */
/*   Updated: 2019/12/11 19:49:37 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Usage: fillit file_name\n");
		return (0);
	}
	if (read_input(argv[1]) < 0)
		ft_putstr("error");
	else
		ft_putstr("valid");
	return(0);
}
