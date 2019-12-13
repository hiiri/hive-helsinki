/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:53:43 by mberglun          #+#    #+#             */
/*   Updated: 2019/12/13 18:19:41 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Helper functions for pieces structures.
*/

/*
** Move coordinates to left and topmost position
** Set width and height properties
*/

void	normalize_piece(t_piece *piece)
{
	int		i;
	int		box[4];

	ft_memset(box, 0, sizeof(int) * 4);
	ft_memset(box, 10, sizeof(int) * 2);
	i = 0;
	while (i < 4)
	{
		box[0] = ft_min(box[0], piece->coords[i][0]);
		box[1] = ft_min(box[1], piece->coords[i][1]);
		box[2] = ft_max(box[2], piece->coords[i][0]);
		box[3] = ft_max(box[3], piece->coords[i][1]);
		++i;
	}
	i = 0;
	while (i < 4)
	{
		piece->coords[i][0] -= box[0];
		piece->coords[i][1] -= box[1];
		++i;
	}
	piece->width = (box[2] - box[0]) + 1;
	piece->height = (box[3] - box[1]) + 1;
}
