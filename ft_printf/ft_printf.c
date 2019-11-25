/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcohen <alcohen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:47:55 by alcohen           #+#    #+#             */
/*   Updated: 2019/11/25 17:45:54 by alcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

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
	va_list	list_ptr;
	int		args;

	args = count_args(format);
	printf("%d\n", args);
	while (*format)
	{
		write(1, &*format, 1);
		format++;
	}
	//va_start(list_ptr, 
	return (0);
}
