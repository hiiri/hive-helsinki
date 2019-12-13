/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:18:13 by mberglun          #+#    #+#             */
/*   Updated: 2019/12/13 20:28:03 by alcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

typedef struct	s_piece
{
	int			coords[4][2];
	int			offset[2];
	int			id;
	int			width;
	int			height;
}				t_piece;

t_piece			**read_input(char *file);
int				validate_tetrimino(char **block, int *coords);
void			block_to_map(char **map, t_piece *piece);
char			**make_map(int size);
void			normalize_piece(t_piece *piece);
int				manager(char *input);
int				solver(char **map, t_piece **pieces, int size, int ix);
void			print_map(char **map);

#endif
