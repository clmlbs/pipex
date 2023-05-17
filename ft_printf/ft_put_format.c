/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:03:20 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/17 18:22:00 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_format(char c, int *count, va_list args)
{
	if (c == 'c')
		ft_putchar_c(va_arg(args, int), count);
	if (c == '%')
		ft_putchar_c(c, count);
	else if (c == 's')
		ft_putstr_s(va_arg(args, char *), count);
	else if (c == 'p')
	{
		ft_putstr_s("0x", count);
		ft_putnbr_p(va_arg(args, void *), count);
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr_i(va_arg(args, int), count);
	else if (c == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), count);
	else if (c == 'x' || c == 'X')
		ft_putnbr_x(va_arg(args, unsigned int), c, count);
}
