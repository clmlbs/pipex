/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:09:28 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/17 09:28:06 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_putnbr_i(int nb, int *count)
{
	char	chiffre;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		*count += 1;
	}
	if (nb >= 10)
	{
		ft_putnbr_i(nb / 10, count);
		ft_putnbr_i(nb % 10, count);
	}
	else
	{
		chiffre = nb + '0';
		write(1, &chiffre, 1);
		*count += 1;
	}
}
