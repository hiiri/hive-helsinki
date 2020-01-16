/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcohen <alcohen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:47:55 by alcohen           #+#    #+#             */
/*   Updated: 2020/01/16 19:35:40 by alcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_args(const char *str)
{
	int count;

	count = 0;
	while (*str++)
		if (*str == '%')
			count++;
	return (count);
}

int				ft_printf(const char *format, ...)
{
	va_list				list_ptr;
	int					args;
	unsigned int		i;
	unsigned int		j;
	char				*flag;

	args = count_args(format);
	i = 0;
	j = 0;
	va_start(list_ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			flag = get_flag(format);
		//	handle_flag(flag, list_ptr);
			j = i;
		}
		else
		{
			ft_putchar(format[i]);
		}
		i++;
	}
	ft_putchar('\n');
	return (0);
}
