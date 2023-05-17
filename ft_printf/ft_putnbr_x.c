/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:16:54 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/18 17:13:36 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_putnbr_x(unsigned int nb, char c, int *count)
{
	char		*base_x;
	char		*base_x_big;

	base_x = "0123456789abcdef";
	base_x_big = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_putnbr_x(nb / 16, c, count);
		ft_putnbr_x(nb % 16, c, count);
	}
	else
	{
		if (c == 'x')
			ft_putchar_c(base_x[nb], count);
		else
			ft_putchar_c(base_x_big[nb], count);
	}
}
