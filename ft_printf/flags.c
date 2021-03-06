/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcohen <alcohen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:59:19 by alcohen           #+#    #+#             */
/*   Updated: 2020/01/21 16:16:25 by alcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_conversion(char *flag)
{
	int		i;
	char	conversion;

	i = 0;
	while (flag[i])
	{
		i++;
	}
	conversion = flag[i-1];
	return (conversion);
}

char	*get_flag(const char *format, int i)
{
	size_t	len;

	len = 1;
	while (format[i + len]) {
		if (ft_strchr("cspdiouxXf%", format[i + len]))
		{
			return (ft_strsub((char const *)format, i + 1, len));
		}
		len++;
	}
	return (NULL);
}

int		handle_flag(char *flag, va_list list_ptr)
{
	char	*str;
	int		d;
	char	conversion;

	conversion = get_conversion(flag);
	printf("\nconversion: %c\n", conversion);
	/*
	if (flag == 's')
	{
		str = va_arg(list_ptr, char *);
		print_str(str);
	}
	*/
	if (conversion == 'd')
	{
		d = va_arg(list_ptr, int);
		print_int(d);
	}
	return (1);
}
