/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:24:21 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/18 17:12:29 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_putnbr_p(void *p, int *count)
{
	char		*base;
	uintptr_t	buf;
	uintptr_t	buf2;

	buf = (uintptr_t)p;
	base = "0123456789abcdef";
	if (buf >= 16)
	{
		buf2 = buf / 16;
		ft_putnbr_p((void *)buf2, count);
		buf = buf % 16;
		ft_putnbr_p((void *)buf, count);
	}
	else
	{
		ft_putchar_c(base[buf], count);
	}
}
