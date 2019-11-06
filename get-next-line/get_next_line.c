/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcohen <alcohen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:25:27 by alcohen           #+#    #+#             */
/*   Updated: 2019/11/06 20:31:48 by alcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include "libft/libft.h"

int	get_next_line(const int fd, char **line)
{
	ssize_t		bytes_read;
	char		buf[BUFF_SIZE + 1];
	size_t		i;
	static char	*tmp_line = "";

	if (fd < 0 || read(fd, 0, 0) == -1)
		return (-1);
	i = 0;
	while (ft_strchr(tmp_line, '\n') == NULL)
	{
		bytes_read = read(fd, buf, BUFF_SIZE);
		buf[bytes_read] = '\0';
		tmp_line = ft_strjoin(tmp_line, buf);
		if (BUFF_SIZE != bytes_read)
			break ;
	}
	while (tmp_line[i] != '\n' && tmp_line[i] != '\0')
		i++;
	*line = ft_strsub(tmp_line, 0, i);
	if (bytes_read != BUFF_SIZE && ft_strequ(tmp_line, ""))
		return (0);
	tmp_line = ft_strsub(tmp_line, i + 1, ft_strlen(tmp_line) - i);
	return (1);
}
