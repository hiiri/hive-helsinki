/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberglun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:48:30 by mberglun          #+#    #+#             */
/*   Updated: 2019/12/13 20:11:11 by alcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	res;
	long	last;

	res = 0;
	while (res * res < nb)
	{
		if (res * res == nb)
		{
			break ;
		}
		else if (res * res > nb)
		{
			res = last;
			break ;
		}
		last = res * res;
		res++;
	}
	return (res);
}
