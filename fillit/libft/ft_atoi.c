/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:03:08 by mberglun          #+#    #+#             */
/*   Updated: 2019/11/12 17:58:52 by mberglun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32 || *str == 48)
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
	{
		sign = -1;
		++str;
	}
	while (*str != '\0')
	{
		if (*str > 57 || *str < 48)
			break ;
		num = (num * 10) + *str - 48;
		++str;
	}
	return (int)(num * sign);
}
